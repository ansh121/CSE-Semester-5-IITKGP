/*********************************************
Name - Anshul Choudhary
Roll No. - 17CS10005
Assignment No. - 4 (Voronoi Diagram)
*********************************************/

#include <fstream>
#include <sstream>
#include <map>
#include <time.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

// Classes contaning attributes and appropriate methods

class VoronoiPoint
{
    public:
        double x, y;
        VoronoiPoint(double px, double py)
        {
            x = px;
            y = py;
        }
        VoronoiPoint()
        {
            x = y = 0.0;
        }
};

int VoronoiPointCompare(const void *p1, const void *p2)
{
    VoronoiPoint *s1, *s2;
    s1 = (VoronoiPoint*)p1; 
    s2 = (VoronoiPoint*)p2;
    if (s1->y < s2->y) return -1;
    else if (s1->y > s2->y) return 1;
    else if (s1->x < s2->x) return -1;
    else if (s1->x > s2->x) return 1;
    else return 0;
}

class Freenode
{
    public:
        Freenode* nextfree;
};

class FreeNodeArrayList
{
    public:
        Freenode* memory;
        FreeNodeArrayList* next;
};

class Freelist
{
    public:
        Freenode* head;
        int nodesize;
};

class Site
{
    public:
        VoronoiPoint coord;
        int sitenbr;
        int refcnt;
};

class VEdge
{
    public:
        VoronoiPoint VertexA;
        VoronoiPoint VertexB;
        VoronoiPoint Left_Site;
        VoronoiPoint Right_Site;
};
class Edge
{
    public:
        double a, b, c;
        Site* Vertices[2];
        Site* Sites[2];
        int edgenbr;
};

class GraphEdge
{
    public:
        double x1, y1, x2, y2;
        GraphEdge* next;
};

class Halfedge
{
    public:
        Halfedge* ELleft;
        Halfedge* ELright;
        Edge* ELedge;
        int ELrefcnt;
        char ELpm;
        Site* vertex;
        double ystar;
        Halfedge *PQnext;
};

class Voronoi
{







    public:


        Voronoi()
        {
            siteidx = 0;
            sites = 0;
            allMemoryList = new FreeNodeArrayList;
            allMemoryList->next = 0;
            allMemoryList->memory = 0;
            currentMemoryBlock = allMemoryList;
            allEdges = 0;
            iteratorEdges = 0;
            minDistanceBetweenSites = 0;
        }

        ~Voronoi()
        {
        }

        vector<VEdge> ComputeVoronoiGraph(vector<VoronoiPoint*> p, double min_Y, double max_Y)
        {
            iteratorEdges = allEdges;
            cleanup();
            cleanupEdges();

            minDistanceBetweenSites = 0;

            nsites = p.size();
            plot = 0;
            triangulate = 0;
            debug = 1;
            sorted = 0;
            freeinit(&sfl, sizeof(Site));

            sites = (Site *)myalloc(nsites*sizeof(*sites));
            xmin = p[0]->x;
            ymin = p[0]->y;
            xmax = p[0]->x;
            ymax = p[0]->y;

            for (int i = 0; i< nsites; i++)
            {
                sites[i].coord.x = p[i]->x;
                sites[i].coord.y = p[i]->y;
                sites[i].sitenbr = i;
                sites[i].refcnt = 0;

                if (p[i]->x < xmin)
                    xmin = p[i]->x;
                else if (p[i]->x > xmax)
                    xmax = p[i]->x;

                if (p[i]->y < ymin)
                    ymin = p[i]->y;
                else if (p[i]->y > ymax)
                    ymax = p[i]->y;
            }

            qsort(sites, nsites, sizeof(*sites), VoronoiPointCompare);

            siteidx = 0;
            geominit();
            double temp = 0;
            if (min_Y > max_Y)
            {
                temp = min_Y;
                min_Y = max_Y;
                max_Y = temp;
            }
            if (min_Y > max_Y)
            {
                temp = min_Y;
                min_Y = max_Y;
                max_Y = temp;
            }
            borderMinX = min_Y;
            borderMinY = min_Y;
            borderMaxX = max_Y;
            borderMaxY = max_Y;

            siteidx = 0;
            voronoi(triangulate);

            p.clear();
            cleanup();
            cleanupEdges();
            clean();
            return total_edges;

        }







    private:


        vector<VEdge> total_edges;
        Freelist    hfl;
        Halfedge *ELleftend, *ELrightend;
        double  xmin, xmax, ymin, ymax, deltax, deltay;
        Site    *sites;
        Freelist sfl;
        Site    *bottomsite;
        Freelist efl;
        Halfedge *PQhash;
        int ntry, totalsearch, total_alloc, PQmin, PQcount, PQhashsize, nedges, nsites, siteidx, sqrt_nsites, nvertices, triangulate, sorted, plot, debug, ELhashsize;
        double  pxmin, pxmax, pymin, pymax, cradius;
        double borderMinX, borderMaxX, borderMinY, borderMaxY;
        FreeNodeArrayList* allMemoryList;
        FreeNodeArrayList* currentMemoryBlock;
        GraphEdge* allEdges;
        GraphEdge* iteratorEdges;
        Halfedge **ELhash;
        double minDistanceBetweenSites;

        
        void clean()
        {
            delete[] sites;
            delete[] PQhash;
            delete[] currentMemoryBlock;
            delete[] allEdges;
            delete[] iteratorEdges;
            delete[] ELhash;
        }

        bool ELinitialize()
        {
            freeinit(&hfl, sizeof **ELhash);
            ELhashsize = 2 * sqrt_nsites;
            ELhash = (Halfedge **)myalloc(sizeof *ELhash * ELhashsize);

            if (ELhash == 0)
                return false;

            for (int i = 0; i<ELhashsize; i += 1) ELhash[i] = (Halfedge *)NULL;
            ELleftend = HEcreate((Edge *)NULL, 0);
            ELrightend = HEcreate((Edge *)NULL, 0);
            ELleftend->ELleft = (Halfedge *)NULL;
            ELleftend->ELright = ELrightend;
            ELrightend->ELleft = ELleftend;
            ELrightend->ELright = (Halfedge *)NULL;
            ELhash[0] = ELleftend;
            ELhash[ELhashsize - 1] = ELrightend;

            return true;
        }

        void geominit()
        {
            double sn;

            freeinit(&efl, sizeof(Edge));
            nvertices = 0;
            nedges = 0;
            sn = (double)nsites + 4;
            sqrt_nsites = (int)sqrt(sn);
            deltay = ymax - ymin;
            deltax = xmax - xmin;
        }

        Halfedge*  HEcreate(Edge *e, int pm)
        {
            Halfedge *answer;
            answer = (Halfedge *)getfree(&hfl);
            answer->ELedge = e;
            answer->ELpm = pm;
            answer->PQnext = (Halfedge *)NULL;
            answer->vertex = (Site *)NULL;
            answer->ELrefcnt = 0;
            return answer;
        }

        void  ELinsert(Halfedge *lb, Halfedge *newHe)
        {
            newHe->ELleft = lb;
            newHe->ELright = lb->ELright;
            (lb->ELright)->ELleft = newHe;
            lb->ELright = newHe;
        }

        Halfedge *  ELgethash(int b)
        {
            Halfedge *he;

            if (b<0 || b >= ELhashsize)
                return((Halfedge *)NULL);
            he = ELhash[b];
            if (he == (Halfedge *)NULL || he->ELedge != (Edge *)-2)
                return (he);

            /* Hash table points to deleted half edge.  Patch as necessary. */
            ELhash[b] = (Halfedge *)NULL;
            if ((he->ELrefcnt -= 1) == 0)
                makefree((Freenode*)he, &hfl);
            return ((Halfedge *)NULL);
        }

        Halfedge *  ELleftbnd(VoronoiPoint *p)
        {
            int i, bucket;
            Halfedge *he;

            bucket = (int)((p->x - xmin) / deltax * ELhashsize);

            if (bucket<0) bucket = 0;
            if (bucket >= ELhashsize) bucket = ELhashsize - 1;

            he = ELgethash(bucket);
            if (he == (Halfedge *)NULL)
            {
                for (i = 1; 1; i += 1)
                {
                    if ((he = ELgethash(bucket - i)) != (Halfedge *)NULL)
                        break;
                    if ((he = ELgethash(bucket + i)) != (Halfedge *)NULL)
                        break;
                };
                totalsearch += i;
            };
            ntry += 1;
            if (he == ELleftend || (he != ELrightend && right_of(he, p)))
            {
                do
                {
                    he = he->ELright;
                } while (he != ELrightend && right_of(he, p));
                he = he->ELleft;
            }
            else
                do
                {
                    he = he->ELleft;
                } while (he != ELleftend && !right_of(he, p));

                if (bucket > 0 && bucket <ELhashsize - 1)
                {
                    if (ELhash[bucket] != (Halfedge *)NULL)
                    {
                        ELhash[bucket]->ELrefcnt -= 1;
                    }
                    ELhash[bucket] = he;
                    ELhash[bucket]->ELrefcnt += 1;
                };
                return (he);
        }
        void ELdelete(Halfedge *he)
        {
            (he->ELleft)->ELright = he->ELright;
            (he->ELright)->ELleft = he->ELleft;
            he->ELedge = (Edge *)-2;
        }


        Halfedge *  ELright(Halfedge *he)
        {
            return (he->ELright);
        }

        Halfedge * ELleft(Halfedge *he)
        {
            return (he->ELleft);
        }


        Site *  leftreg(Halfedge *he)
        {
            if (he->ELedge == (Edge *)NULL)
                return(bottomsite);
            return(he->ELpm == 0 ? he->ELedge->Sites[0] : he->ELedge->Sites[1]);
        }

        Site * rightreg(Halfedge *he)
        {
            if (he->ELedge == (Edge *)NULL)
                return(bottomsite);
            return(he->ELpm == 0 ? he->ELedge->Sites[1] : he->ELedge->Sites[0]);
        }

        Edge * bisect(Site *s1, Site *s2)
        {
            double dx, dy, adx, ady;
            Edge *newedge;

            newedge = (Edge *)getfree(&efl);

            newedge->Sites[0] = s1;
            newedge->Sites[1] = s2;
            ref(s1);
            ref(s2);
            newedge->Vertices[0] = (Site *)NULL; 
            newedge->Vertices[1] = (Site *)NULL;

            dx = s2->coord.x - s1->coord.x;  
            dy = s2->coord.y - s1->coord.y;
            adx = dx>0 ? dx : -dx;        
            ady = dy>0 ? dy : -dy;
            newedge->c = (double)(s1->coord.x * dx + s1->coord.y * dy + (dx*dx + dy*dy)*0.5);

            if (adx>ady)
            {
                newedge->a = 1.0; newedge->b = dy / dx; newedge->c /= dx;
            }
            else
            {
                newedge->b = 1.0; newedge->a = dx / dy; newedge->c /= dy;
            };

            newedge->edgenbr = nedges;

            nedges += 1;
            return(newedge);
        }

        Site * intersect(Halfedge *el1, Halfedge *el2, VoronoiPoint *p=0)
        {
            Edge *e1, *e2, *e;
            Halfedge *el;
            double d, xint, yint;
            int right_of_site;
            Site *v;

            e1 = el1->ELedge;
            e2 = el2->ELedge;
            if (e1 == (Edge*)NULL || e2 == (Edge*)NULL)
                return ((Site *)NULL);

            if (e1->Sites[1] == e2->Sites[1])
                return ((Site *)NULL);

            d = e1->a * e2->b - e1->b * e2->a;
            if (-1.0e-10<d && d<1.0e-10)
                return ((Site *)NULL);

            xint = (e1->c*e2->b - e2->c*e1->b) / d;
            yint = (e2->c*e1->a - e1->c*e2->a) / d;

            if ((e1->Sites[1]->coord.y < e2->Sites[1]->coord.y) ||
                (e1->Sites[1]->coord.y == e2->Sites[1]->coord.y &&
                    e1->Sites[1]->coord.x < e2->Sites[1]->coord.x))
            {
                el = el1;
                e = e1;
            }
            else
            {
                el = el2;
                e = e2;
            };

            right_of_site = xint >= e->Sites[1]->coord.x;
            if ((right_of_site && el->ELpm == 0) || (!right_of_site && el->ELpm == 1))
                return ((Site *)NULL);

            v = (Site *)getfree(&sfl);
            v->refcnt = 0;
            v->coord.x = xint;
            v->coord.y = yint;
            return(v);
        }
        int right_of(Halfedge *el, VoronoiPoint *p)
        {
            Edge *e;
            Site *topsite;
            int right_of_site, above, fast;
            double dxp, dyp, dxs, t1, t2, t3, yl;

            e = el->ELedge;
            topsite = e->Sites[1];
            right_of_site = p->x > topsite->coord.x;
            if (right_of_site && el->ELpm == 0) return(1);
            if (!right_of_site && el->ELpm == 1) return (0);

            if (e->a == 1.0)
            {
                dyp = p->y - topsite->coord.y;
                dxp = p->x - topsite->coord.x;
                fast = 0;
                if ((!right_of_site & (e->b<0.0)) | (right_of_site & (e->b >= 0.0)))
                {
                    above = dyp >= e->b*dxp;
                    fast = above;
                }
                else
                {
                    above = p->x + p->y*e->b > e->c;
                    if (e->b<0.0) above = !above;
                    if (!above) fast = 1;
                };
                if (!fast)
                {
                    dxs = topsite->coord.x - (e->Sites[0])->coord.x;
                    above = e->b * (dxp*dxp - dyp*dyp) <
                        dxs*dyp*(1.0 + 2.0*dxp / dxs + e->b*e->b);
                    if (e->b<0.0) above = !above;
                };
            }
            else
            {
                yl = e->c - e->a*p->x;
                t1 = p->y - yl;
                t2 = p->x - topsite->coord.x;
                t3 = yl - topsite->coord.y;
                above = t1*t1 > t2*t2 + t3*t3;
            };
            return (el->ELpm == 0 ? above : !above);
        }

        void endpoint(Edge *e, int lr, Site * s)
        {
            e->Vertices[lr] = s;
            ref(s);
            if (e->Vertices[1 - lr] == (Site *)NULL)
                return;

            clip_line(e);

            deref(e->Sites[0]);
            deref(e->Sites[1]);
            makefree((Freenode*)e, &efl);
        }

        double dist(Site *s, Site *t)
        {
            double dx, dy;
            dx = s->coord.x - t->coord.x;
            dy = s->coord.y - t->coord.y;
            return (double)(sqrt(dx*dx + dy*dy));
        }


        void makevertex(Site *v)
        {
            v->sitenbr = nvertices;
            nvertices += 1;
        }


        void deref(Site *v)
        {
            v->refcnt -= 1;
            if (v->refcnt == 0)
                makefree((Freenode*)v, &sfl);
        }

        void  ref(Site *v)
        {
            v->refcnt += 1;
        }

        void PQinsert(Halfedge *he, Site * v, double offset)
        {
            Halfedge *last, *next;

            he->vertex = v;
            ref(v);
            he->ystar = (double)(v->coord.y + offset);
            last = &PQhash[PQbucket(he)];
            while ((next = last->PQnext) != (Halfedge *)NULL &&
                (he->ystar  > next->ystar ||
                    (he->ystar == next->ystar && v->coord.x > next->vertex->coord.x)))
            {
                last = next;
            };
            he->PQnext = last->PQnext;
            last->PQnext = he;
            PQcount += 1;
        }

        void PQdelete(Halfedge *he)
        {
            Halfedge *last;

            if (he->vertex != (Site *)NULL)
            {
                last = &PQhash[PQbucket(he)];
                while (last->PQnext != he)
                    last = last->PQnext;

                last->PQnext = he->PQnext;
                PQcount -= 1;
                deref(he->vertex);
                he->vertex = (Site *)NULL;
            };
        }

        int  PQbucket(Halfedge *he)
        {
            int bucket;

            bucket = (int)((he->ystar - ymin) / deltay * PQhashsize);
            if (bucket<0) bucket = 0;
            if (bucket >= PQhashsize) bucket = PQhashsize - 1;
            if (bucket < PQmin) PQmin = bucket;
            return(bucket);
        }



        int PQempty()
        {
            return(PQcount == 0);
        }


        VoronoiPoint PQ_min()
        {
            VoronoiPoint answer;

            while (PQhash[PQmin].PQnext == (Halfedge *)NULL) { PQmin += 1; };
            answer.x = PQhash[PQmin].PQnext->vertex->coord.x;
            answer.y = PQhash[PQmin].PQnext->ystar;
            return (answer);
        }

        Halfedge * PQextractmin()
        {
            Halfedge *curr;

            curr = PQhash[PQmin].PQnext;
            PQhash[PQmin].PQnext = curr->PQnext;
            PQcount -= 1;
            return(curr);
        }


        bool PQinitialize()
        {
            int i;

            PQcount = 0;
            PQmin = 0;
            PQhashsize = 4 * sqrt_nsites;
            PQhash = (Halfedge *)myalloc(PQhashsize * sizeof *PQhash);

            if (PQhash == 0)
                return false;

            for (i = 0; i<PQhashsize; i += 1) PQhash[i].PQnext = (Halfedge *)NULL;

            return true;
        }


        void freeinit(Freelist *fl, int size)
        {
            fl->head = (Freenode *)NULL;
            fl->nodesize = size;
        }

        char *  getfree(Freelist *fl)
        {
            int i;
            Freenode *t;

            if (fl->head == (Freenode *)NULL)
            {
                t = (Freenode *)myalloc(sqrt_nsites * fl->nodesize);

                if (t == 0)
                    return 0;

                currentMemoryBlock->next = new FreeNodeArrayList;
                currentMemoryBlock = currentMemoryBlock->next;
                currentMemoryBlock->memory = t;
                currentMemoryBlock->next = 0;

                for (i = 0; i<sqrt_nsites; i += 1)
                    makefree((Freenode *)((char *)t + i*fl->nodesize), fl);
            };
            t = fl->head;
            fl->head = (fl->head)->nextfree;
            return((char *)t);
        }



        void makefree(Freenode *curr, Freelist *fl)
        {
            curr->nextfree = fl->head;
            fl->head = curr;
        }

        void  cleanup()
        {
            if (sites != 0)
            {
                free(sites);
                sites = 0;
            }

            FreeNodeArrayList* current = 0, *prev = 0;

            current = prev = allMemoryList;

            while (current->next != 0)
            {
                prev = current;
                current = current->next;
                free(prev->memory);
                delete prev;
                prev = 0;
            }

            if (current != 0 && current->memory != 0)
            {
                free(current->memory);
                delete current;
            }

            allMemoryList = new FreeNodeArrayList;
            allMemoryList->next = 0;
            allMemoryList->memory = 0;
            currentMemoryBlock = allMemoryList;
        }

        void cleanupEdges()
        {
            GraphEdge* geCurrent = 0, *gePrev = 0;
            geCurrent = gePrev = allEdges;

            while (geCurrent != 0 && geCurrent->next != 0)
            {
                gePrev = geCurrent;
                geCurrent = geCurrent->next;
                delete gePrev;
            }
            allEdges = 0;
        }

        void pushGraphEdge(double x1, double y1, double x2, double y2)
        {
            GraphEdge* newEdge = new GraphEdge;
            newEdge->next = allEdges;
            allEdges = newEdge;
            newEdge->x1 = x1;
            newEdge->y1 = y1;
            newEdge->x2 = x2;
            newEdge->y2 = y2;
        }


        char * myalloc(unsigned n)
        {
            char *t = 0;
            t = (char*)malloc(n);
            total_alloc += n;
            return(t);
        }

        void  line(double x1, double y1, double x2, double y2)
        {
            pushGraphEdge(x1, y1, x2, y2);

        }
        void  clip_line(Edge *e)
        {
            Site *s1, *s2;
            double x1 = 0, x2 = 0, y1 = 0, y2 = 0, temp = 0;;

            x1 = e->Sites[0]->coord.x;
            x2 = e->Sites[1]->coord.x;
            y1 = e->Sites[0]->coord.y;
            y2 = e->Sites[1]->coord.y;

            if (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) < minDistanceBetweenSites)
            {
                return;
            }
            pxmin = borderMinX;
            pxmax = borderMaxX;
            pymin = borderMinY;
            pymax = borderMaxY;

            if (e->a == 1.0 && e->b >= 0.0)
            {
                s1 = e->Vertices[1];
                s2 = e->Vertices[0];
            }
            else
            {
                s1 = e->Vertices[0];
                s2 = e->Vertices[1];
            };

            if (e->a == 1.0)
            {
                y1 = pymin;
                if (s1 != (Site *)NULL && s1->coord.y > pymin)
                    y1 = s1->coord.y;
                if (y1>pymax)
                    y1 = pymax;
                x1 = e->c - e->b * y1;
                y2 = pymax;
                if (s2 != (Site *)NULL && s2->coord.y < pymax)
                    y2 = s2->coord.y;

                if (y2<pymin)
                    y2 = pymin;
                x2 = (e->c) - (e->b) * y2;
                if (((x1> pxmax) & (x2>pxmax)) | ((x1<pxmin)&(x2<pxmin)))
                    return;
                if (x1> pxmax)
                {
                    x1 = pxmax; y1 = (e->c - x1) / e->b;
                };
                if (x1<pxmin)
                {
                    x1 = pxmin; y1 = (e->c - x1) / e->b;
                };
                if (x2>pxmax)
                {
                    x2 = pxmax; y2 = (e->c - x2) / e->b;
                };
                if (x2<pxmin)
                {
                    x2 = pxmin; y2 = (e->c - x2) / e->b;
                };
            }
            else
            {
                x1 = pxmin;
                if (s1 != (Site *)NULL && s1->coord.x > pxmin)
                    x1 = s1->coord.x;
                if (x1>pxmax)
                    x1 = pxmax;
                y1 = e->c - e->a * x1;
                x2 = pxmax;
                if (s2 != (Site *)NULL && s2->coord.x < pxmax)
                    x2 = s2->coord.x;
                if (x2<pxmin)
                {
                    x2 = pxmin;
                }
                y2 = e->c - e->a * x2;
                if (((y1> pymax) & (y2>pymax)) | ((y1<pymin)&(y2<pymin)))
                    return;
                if (y1> pymax)
                {
                    y1 = pymax; x1 = (e->c - y1) / e->a;
                };
                if (y1<pymin)
                {
                    y1 = pymin; x1 = (e->c - y1) / e->a;
                };
                if (y2>pymax)
                {
                    y2 = pymax; x2 = (e->c - y2) / e->a;
                };
                if (y2<pymin)
                {
                    y2 = pymin; x2 = (e->c - y2) / e->a;
                };
            };

            VEdge ee;
            ee.Left_Site = e->Sites[0]->coord;
            ee.Right_Site = e->Sites[1]->coord;
            ee.VertexA.x = x1;
            ee.VertexA.y = y1;
            ee.VertexB.x = x2;
            ee.VertexB.y = y2;

            total_edges.push_back(ee);
            line(x1, y1, x2, y2);
        }

        bool  voronoi(int triangulate)
        {
            Site *newsite, *bot, *top, *temp, *p;
            Site *v;
            VoronoiPoint newintstar;
            int pm;
            Halfedge *lbnd, *rbnd, *llbnd, *rrbnd, *bisector;
            Edge *e;

            PQinitialize();
            bottomsite = nextone();
            bool retval = ELinitialize();

            if (!retval)
                return false;

            newsite = nextone();
            while (1)
            {

                if (!PQempty())
                    newintstar = PQ_min();
                if (newsite != (Site *)NULL && (PQempty() || newsite->coord.y < newintstar.y
                    || (newsite->coord.y == newintstar.y && newsite->coord.x < newintstar.x)))
                {
                    lbnd = ELleftbnd(&(newsite->coord));
                    rbnd = ELright(lbnd);
                    bot = rightreg(lbnd);
                    e = bisect(bot, newsite);
                    bisector = HEcreate(e, 0);
                    ELinsert(lbnd, bisector);

                    if ((p = intersect(lbnd, bisector)) != (Site *)NULL)
                    {
                        PQdelete(lbnd);
                        PQinsert(lbnd, p, dist(p, newsite));
                    };
                    lbnd = bisector;
                    bisector = HEcreate(e, 1);
                    ELinsert(lbnd, bisector);

                    if ((p = intersect(bisector, rbnd)) != (Site *)NULL)
                    {
                        PQinsert(bisector, p, dist(p, newsite));
                    };
                    newsite = nextone();
                }
                else if (!PQempty())
                {
                    lbnd = PQextractmin();
                    llbnd = ELleft(lbnd);
                    rbnd = ELright(lbnd);
                    rrbnd = ELright(rbnd);
                    bot = leftreg(lbnd);
                    top = rightreg(rbnd);
                    v = lbnd->vertex;
                    makevertex(v);
                    endpoint(lbnd->ELedge, lbnd->ELpm, v);
                    endpoint(rbnd->ELedge, rbnd->ELpm, v);
                    ELdelete(lbnd);
                    PQdelete(rbnd);
                    ELdelete(rbnd);
                    pm = 0;
                    if (bot->coord.y > top->coord.y)
                    {
                        temp = bot;
                        bot = top;
                        top = temp;
                        pm = 1;
                    }
                    e = bisect(bot, top);
                    bisector = HEcreate(e, pm);
                    ELinsert(llbnd, bisector);
                    endpoint(e, 1 - pm, v);
                    deref(v);
                    if ((p = intersect(llbnd, bisector)) != (Site *)NULL)
                    {
                        PQdelete(llbnd);
                        PQinsert(llbnd, p, dist(p, bot));
                    };

                    if ((p = intersect(bisector, rrbnd)) != (Site *)NULL)
                    {
                        PQinsert(bisector, p, dist(p, bot));
                    };
                }
                else break;
            };

            for (lbnd = ELright(ELleftend); lbnd != ELrightend; lbnd = ELright(lbnd))
            {
                e = lbnd->ELedge;

                clip_line(e);
            };

            cleanup();
            return true;
        }

        Site * nextone()
        {
            Site *s;
            if (siteidx < nsites)
            {
                s = &sites[siteidx];
                siteidx += 1;
                return(s);
            }
            else
                return((Site *)NULL);
        }

};










Voronoi* ComputeVoronoi;
vector<VEdge> edges;
vector<VoronoiPoint*> vertex;













// Main Function

int main()
{
    int leftgap = 200;

    vector<VoronoiPoint*>::iterator it;
	int iou = 0;

	for (it = vertex.begin(); it != vertex.end(); it++) 
    {
        delete((*it));
    }

	vertex.clear();
	edges.clear();

	int n;
	cout << "Enter number of sites: ";
	cin >> n ;

	cout << "\nNumber of random sites: "<< n << endl;

    srand(time(0));

    for(int i=0; i<n; i++)
    {
        double temp1 = (rand()%20000)/10000.0;
        double temp2 = (rand()%20000)/10000.0;

        vertex.push_back(new VoronoiPoint(temp1, temp2));
    }

	ComputeVoronoi = new Voronoi();
	double min_Y = -10;
	double max_Y = 10;
	edges = ComputeVoronoi->ComputeVoronoiGraph(vertex, min_Y, max_Y);
	delete ComputeVoronoi;

    map <pair<double, double>, double> mapping;

    for(it = vertex.begin(); it!=vertex.end(); it++)
    {
        mapping[make_pair((*it)->x, (*it)->y)] = 1E+20;
    }

    vector<VEdge>::iterator it2;
	for(it2 = edges.begin(); it2!=edges.end(); it2++)
    {
        double dist_left = 100;
        double dist_right = 100;
        if(it2->VertexA.x == it2->VertexB.x)
        {
            dist_left = fabs(it2->VertexA.x - it2->Left_Site.x);
            dist_right = fabs(it2->Right_Site.x - it2->VertexA.x);
        }
        else
        {
            double slope = (it2->VertexA.y - it2->VertexB.y)/(it2->VertexA.x - it2->VertexB.x);
            double intercept = it2->VertexA.y -(slope*it2->VertexA.x);

            dist_left = fabs(it2->Left_Site.y - slope*it2->Left_Site.x - intercept)/sqrt((slope*slope) + 1);
            dist_right = fabs(it2->Right_Site.y - slope*it2->Right_Site.x - intercept)/sqrt((slope*slope) + 1);
        }
        mapping[make_pair(it2->Left_Site.x, it2->Left_Site.y)] = min(mapping[make_pair(it2->Left_Site.x, it2->Left_Site.y)], dist_left);
        mapping[make_pair(it2->Right_Site.x, it2->Right_Site.y)] = min(mapping[make_pair(it2->Right_Site.x, it2->Right_Site.y)], dist_right);
    }


    string svg_text_begin="<svg height=\"1000\" width=\"1000\">\n<rect width=\"1000\" height=\"1000\" style=\"fill:rgb(255,255,255); stroke-width:0; stroke:rgb(0,0,0)\" />\n";
    string point_string = "";
    
    int factor = 200;

    for(it = vertex.begin(); it!=vertex.end(); it++)
    {

        cout << "(" << (*it)->x << " , " << (*it)->y << ")" << endl;

        stringstream x_coord;
        stringstream y_coord;
        stringstream incircle_radius;
        x_coord << factor*((*it)->x) + leftgap;
        y_coord << factor*((*it)->y) + leftgap;
        incircle_radius << (mapping[make_pair((*it)->x, (*it)->y)])*factor;
        point_string =  point_string + "<circle cx=\""+ x_coord.str() +"\" cy=\""+ y_coord.str() +"\" r=\"1\" stroke=\"black\" stroke-width=\"3\"/>\n";
        point_string =  point_string + "<circle cx=\""+ x_coord.str() +"\" cy=\""+ y_coord.str() +"\" r=\""+incircle_radius.str()+"\" stroke=\"#A52A2A\" stroke-width=\"0\" fill=\"#ff0000\" fill-opacity=\"0.4\"/>\n";
    }

    string edge_string = "";
    for(it2 = edges.begin(); it2!=edges.end(); it2++)
    {
        stringstream p1_x;
        stringstream p1_y;
        stringstream p2_x;
        stringstream p2_y;

        p1_x << it2->VertexA.x*factor + leftgap;
        p1_y << it2->VertexA.y*factor + leftgap;
        p2_x << it2->VertexB.x*factor + leftgap;
        p2_y << it2->VertexB.y*factor + leftgap;

        edge_string = edge_string + "<line x1=\""+p1_x.str()+"\" y1=\""+p1_y.str()+"\" x2=\""+p2_x.str()+"\" y2=\""+p2_y.str()+"\" style=\"stroke:rgb(240,0,0);stroke-width:1; opacity=0.4/>\" />\n";
    }

    string svg_text_end = "</svg>";

    stringstream result_svg_code;
    result_svg_code << svg_text_begin << point_string << edge_string << svg_text_end << endl;

    cout << result_svg_code.str();

    ofstream file;
    file.open("t4.svg");
    file << result_svg_code.str();
    file.close();

}

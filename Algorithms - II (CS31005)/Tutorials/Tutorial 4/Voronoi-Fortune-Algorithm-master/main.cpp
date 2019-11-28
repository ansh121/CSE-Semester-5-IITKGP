#include <fstream>
#include <sstream>
#include "voronoi.h"
#include <map>
#include <time.h>

using namespace std;


Voronoi* ComputeVoronoi;
vector<VEdge> edges;
vector<VoronoiPoint*> vertex;

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

        stringstream x_string;
        stringstream y_string;
        stringstream r_string;
        x_string << factor*((*it)->x) + leftgap;
        y_string << factor*((*it)->y) + leftgap;
        r_string << (mapping[make_pair((*it)->x, (*it)->y)])*factor;
        point_string =  point_string + "<circle cx=\""+ x_string.str() +"\" cy=\""+ y_string.str() +"\" r=\"1\" stroke=\"black\" stroke-width=\"3\"/>\n";
        point_string =  point_string + "<circle cx=\""+ x_string.str() +"\" cy=\""+ y_string.str() +"\" r=\""+r_string.str()+"\" stroke=\"#A52A2A\" stroke-width=\"0\" fill=\"#ff0000\" fill-opacity=\"0.4\"/>\n";
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

        edge_string = edge_string + "<line x1=\""+p1_x.str()+"\" y1=\""+p1_y.str()+"\" x2=\""+p2_x.str()+"\" y2=\""+p2_y.str()+"\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
    }

    string svg_text_end = "</svg>";

    stringstream result;
    result << svg_text_begin << point_string << edge_string << svg_text_end << endl;

    cout << result.str();

    ofstream file;
    file.open("Voronoi_Diagram.svg");
    file << result.str();
    file.close();

}

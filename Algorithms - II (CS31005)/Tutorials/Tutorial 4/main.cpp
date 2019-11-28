#include <fstream>
#include <sstream>
#include "voronoi.h"
#include <map>


Voronoi* vdg;
vector<VoronoiPoint*> ver;
vector<VEdge> edges;

int main(int argc, char **argv)
{
    int offset = 200;
    int factor = 200;

	int iou = 0;
	for (vector<VoronoiPoint*>::iterator i = ver.begin(); i != ver.end(); i++)
		delete((*i));
	ver.clear();
	edges.clear();

	int n, seed;
	cout << "Enter the number of random sites: ";
	cin >> n ;
	cout << "Enter seed: ";
	cin >> seed;

	cout << "\nNumber of random sites: "<< n << endl;
	cout << "Seed: " << seed << endl;

    srand(seed);

    for(int i=0; i<n; i++)
    {
        double temp1 = (rand()%2000)/1000.0;
        double temp2 = (rand()%2000)/1000.0;

        ver.push_back(new VoronoiPoint(temp1, temp2));
    }
    /*
    ver.clear();
    ver.push_back(new VoronoiPoint(1.5, 1.5));
    ver.push_back(new VoronoiPoint(0.75, 0.99));
    */
	vdg = new Voronoi();
	double minY = -10;
	double maxY = 10;
	edges = vdg->ComputeVoronoiGraph(ver, minY, maxY);
	delete vdg;

    map <pair<double, double>, double> mapping;

    for(vector<VoronoiPoint*>::iterator i = ver.begin(); i!=ver.end(); i++)
    {
        mapping[ std::make_pair((*i)->x, (*i)->y) ] = 1E+20;
    }

	for(vector<VEdge>::iterator j = edges.begin(); j!=edges.end(); j++)
    {
        double distance_left = 100;
        double distance_right = 100;
        if(j->VertexA.x == j->VertexB.x)
        {
            distance_left = fabs(j->VertexA.x - j->Left_Site.x);
            distance_right = fabs(j->Right_Site.x - j->VertexA.x);
        }
        else
        {
            double slope = (j->VertexA.y - j->VertexB.y)/(j->VertexA.x - j->VertexB.x);
            double intercept = j->VertexA.y -(slope*j->VertexA.x);

            distance_left = fabs(j->Left_Site.y - slope*j->Left_Site.x - intercept)/sqrt((slope*slope) + 1);
            distance_right = fabs(j->Right_Site.y - slope*j->Right_Site.x - intercept)/sqrt((slope*slope) + 1);
        }
        mapping[std::make_pair(j->Left_Site.x, j->Left_Site.y)] = min(mapping[std::make_pair(j->Left_Site.x, j->Left_Site.y)], distance_left);
        mapping[std::make_pair(j->Right_Site.x, j->Right_Site.y)] = min(mapping[std::make_pair(j->Right_Site.x, j->Right_Site.y)], distance_right);
    }


    string svg_text_begin="<svg height=\"1000\" width=\"1000\" xmlns=\"http://www.w3.org/2000/svg\">\n<rect width=\"1000\" height=\"1000\" style=\"fill:rgb(255,255,255); stroke-width:0; stroke:rgb(0,0,0)\" />\n";
    string point_string = "";
    for(vector<VoronoiPoint*>::iterator i = ver.begin(); i!=ver.end(); i++)
    {

        cout << (*i)->x << " " << (*i)->y << endl;

        stringstream x_string;
        stringstream y_string;
        stringstream r_string;
        x_string << factor*((*i)->x) + offset;
        y_string << factor*((*i)->y) + offset;
        r_string << (mapping[std::make_pair((*i)->x, (*i)->y)])*factor;
        point_string =  point_string + "<circle cx=\""+ x_string.str() +"\" cy=\""+ y_string.str() +"\" r=\"1\" stroke=\"black\" stroke-width=\"3\"/>\n";
        point_string =  point_string + "<circle cx=\""+ x_string.str() +"\" cy=\""+ y_string.str() +"\" r=\""+r_string.str()+"\" stroke=\"#0066ff\" stroke-width=\"0\" fill=\"#0066ff\" fill-opacity=\"0.4\"/>\n";
    }

    string edge_string = "";
    for(vector<VEdge>::iterator j = edges.begin(); j!=edges.end(); j++)
    {
        stringstream p1_x;
        stringstream p1_y;
        stringstream p2_x;
        stringstream p2_y;

        p1_x << j->VertexA.x*factor + offset;
        p1_y << j->VertexA.y*factor + offset;
        p2_x << j->VertexB.x*factor + offset;
        p2_y << j->VertexB.y*factor + offset;

        edge_string = edge_string + "<line x1=\""+p1_x.str()+"\" y1=\""+p1_y.str()+"\" x2=\""+p2_x.str()+"\" y2=\""+p2_y.str()+"\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
    }

    string svg_text_end = "</svg>";

    stringstream result;
    result << svg_text_begin << point_string << edge_string << svg_text_end << endl;

    cout << result.str();

    ofstream file;
    file.open("diagram.svg");
    file << result.str();
    file.close();

}

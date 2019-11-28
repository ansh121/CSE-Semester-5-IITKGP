#include<GL\glut.h>
#include "voronoi.h"

Voronoi* vdg;
vector<VoronoiPoint*> ver;
vector<VEdge> edges;

void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPointSize(5.0);
	glLineWidth(1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 1.0f);
	for (vector<VoronoiPoint*>::iterator i = ver.begin(); i != ver.end(); i++)
		glVertex2d((*i)->x, (*i)->y);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, .8f, .5f);
	for (vector<VEdge>::iterator j = edges.begin(); j != edges.end(); j++)
	{
		glVertex2d(j->VertexA.x, j->VertexA.y);
		glVertex2d(j->VertexB.x, j->VertexB.y);
	}
	glEnd();
	glFlush();
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height)
		gluOrtho2D(-3.0 * aspect, 3.0 * aspect, -3.0, 3.0);
	else
		gluOrtho2D(-3.0, 3.0, -3.0 / aspect, 3.0 / aspect);
}


int main(int argc, char **argv)
{
	system("mode con: cols=100 lines=2500");
	int iou = 0;
	for (vector<VoronoiPoint*>::iterator i = ver.begin(); i != ver.end(); i++)
		delete((*i));
	ver.clear();
	edges.clear();
	ver.push_back(new VoronoiPoint(-0.1, -0.1));
	ver.push_back(new VoronoiPoint(0.1, 0.1));
	ver.push_back(new VoronoiPoint(-0.5, 1));
	ver.push_back(new VoronoiPoint(-0.5, -1));
	ver.push_back(new VoronoiPoint(1, -0.5));
	ver.push_back(new VoronoiPoint(-1, -0.5));
	ver.push_back(new VoronoiPoint(0, 1));
	ver.push_back(new VoronoiPoint(0, -1));
	ver.push_back(new VoronoiPoint(1, 0));
	ver.push_back(new VoronoiPoint(-1, 0));
	ver.push_back(new VoronoiPoint(0.5, 1));
	ver.push_back(new VoronoiPoint(0.5, -1));
	ver.push_back(new VoronoiPoint(1, 0.5));
	ver.push_back(new VoronoiPoint(-1, 0.5));
	ver.push_back(new VoronoiPoint(-1, 1));
	ver.push_back(new VoronoiPoint(-1, -1));
	ver.push_back(new VoronoiPoint(1, 1));
	ver.push_back(new VoronoiPoint(1, -1));

	ver.push_back(new VoronoiPoint(2.017513020833333393, -0.574468085106383031));
	ver.push_back(new VoronoiPoint(1.025000000000000355, -0.574468085106383031));
	ver.push_back(new VoronoiPoint(1.851497395833333393, -0.489361702127659504));
	ver.push_back(new VoronoiPoint(1.189388020833333837, -0.489361702127659504));
	ver.push_back(new VoronoiPoint(1.680924479166666874, -0.404255319148936199));
	ver.push_back(new VoronoiPoint(1.347265625000000355, -0.404255319148936199));
	ver.push_back(new VoronoiPoint(1.520442708333333837, -0.361702127659574435));
	ver.push_back(new VoronoiPoint(2.231705729166666874, -0.106382978723404298));
	ver.push_back(new VoronoiPoint(1.963802083333333393, -0.106382978723404298));
	ver.push_back(new VoronoiPoint(2.126562500000000355, -0.063829787234042534));
	ver.push_back(new VoronoiPoint(1.800065104166666874, -0.063829787234042534));
	ver.push_back(new VoronoiPoint(1.624934895833333393, -0.063829787234042534));
	ver.push_back(new VoronoiPoint(1.458593750000000355, -0.063829787234042534));
	ver.push_back(new VoronoiPoint(1.293554687500000355, -0.063829787234042534));
	ver.push_back(new VoronoiPoint(1.139908854166666874, -0.063829787234042534));
	ver.push_back(new VoronoiPoint(1.086848958333333837, 0.234042553191489366));
	ver.push_back(new VoronoiPoint(2.152278645833333393, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(2.074479166666666874, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.825781250000000355, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.771419270833333393, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.711848958333333393, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.652929687500000355, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.598242187500000355, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.545833333333333837, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.489518229166666874, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.432877604166666874, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.377213541666666874, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.320247395833333837, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.266861979166666874, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.214778645833333837, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.164648437500000355, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.113541666666666874, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(1.055924479166666874, 0.446808510638297740));
	ver.push_back(new VoronoiPoint(2.231705729166666874, 0.531914893617021267));
	ver.push_back(new VoronoiPoint(2.178320312500000355, 0.531914893617021267));
	ver.push_back(new VoronoiPoint(2.100520833333333393, 0.531914893617021267));
	ver.push_back(new VoronoiPoint(2.045833333333333393, 0.531914893617021267));
	ver.push_back(new VoronoiPoint(1.990494791666666874, 0.531914893617021267));
	ver.push_back(new VoronoiPoint(1.911393229166666874, 0.531914893617021267));
	ver.push_back(new VoronoiPoint(2.205013020833333393, 0.617021276595744794));
	ver.push_back(new VoronoiPoint(2.126562500000000355, 0.617021276595744794));
	ver.push_back(new VoronoiPoint(2.017513020833333393, 0.617021276595744794));
	ver.push_back(new VoronoiPoint(1.937434895833333393, 0.617021276595744794));
	ver.push_back(new VoronoiPoint(1.881445312500000355, 0.617021276595744794));
	ver.push_back(new VoronoiPoint(1.139908854166666874, 0.617021276595744794));
	ver.push_back(new VoronoiPoint(1.025000000000000355, 0.617021276595744794));
	ver.push_back(new VoronoiPoint(1.963802083333333393, 0.659574468085106336));
	ver.push_back(new VoronoiPoint(1.851497395833333837, 0.659574468085106336));
	ver.push_back(new VoronoiPoint(1.293554687500000355, 0.659574468085106336));
	ver.push_back(new VoronoiPoint(1.240169270833333837, 0.659574468085106336));
	ver.push_back(new VoronoiPoint(1.189388020833333837, 0.659574468085106336));
	ver.push_back(new VoronoiPoint(1.800065104166666874, 0.744680851063829863));
	ver.push_back(new VoronoiPoint(1.742447916666666874, 0.744680851063829863));
	ver.push_back(new VoronoiPoint(1.680924479166666874, 0.744680851063829863));
	ver.push_back(new VoronoiPoint(1.458593750000000355, 0.744680851063829863));
	ver.push_back(new VoronoiPoint(1.407486979166666874, 0.744680851063829863));
	ver.push_back(new VoronoiPoint(1.347265625000000355, 0.744680851063829863));
	ver.push_back(new VoronoiPoint(1.624934895833333837, 0.829787234042553168));
	ver.push_back(new VoronoiPoint(1.571223958333333837, 0.829787234042553168));
	ver.push_back(new VoronoiPoint(1.520442708333333837, 0.829787234042553168));
	ver.push_back(new VoronoiPoint(-0.261194643490678224, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.261194643490678224, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.153893051668114067, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.153893051668114067, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.363659573355693988, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.363659573355693988, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.036153138739797752, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.036153138739797752, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.462967001241743947, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.462967001241743947, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.097175131511157087, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.097175131511157087, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.559942424040845044, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.559942424040845044, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.208321571865569322, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.208321571865569322, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.655076493418098149, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.655076493418098149, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.312895577228335942, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.312895577228335942, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.748693746906758495, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.748693746906758495, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.413645344658276626, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.413645344658276626, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.841024318393457371, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.841024318393457371, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.511710405892882747, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.511710405892882747, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.932239626539499433, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-0.932239626539499433, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.607716545146089526, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.607716545146089526, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.024999999999999467, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.024999999999999467, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.702058651501696218, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.702058651501696218, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.124999999999999556, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.124999999999999556, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.795008061072074224, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.795008061072074224, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.224999999999999645, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.224999999999999645, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.886762354257207619, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.886762354257207619, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.324999999999999734, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.324999999999999734, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.977471613750350077, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(0.977471613750350077, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.424999999999999822, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.424999999999999822, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.075000000000000178, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.075000000000000178, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.524999999999999467, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.524999999999999467, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.175000000000000711, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.175000000000000711, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.625000000000000000, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.625000000000000000, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.275000000000000355, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.275000000000000355, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.724999999999999645, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.724999999999999645, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.375000000000000444, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.375000000000000444, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.824999999999999734, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.824999999999999734, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.475000000000000533, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.475000000000000533, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.924999999999999822, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.924999999999999822, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.575000000000000178, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.575000000000000178, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-2.024999999999999467, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-2.024999999999999467, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.675000000000000711, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.675000000000000711, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-2.125000000000000000, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-2.125000000000000000, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.775000000000000355, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.775000000000000355, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(-2.224999999999999645, 1.399999999999999911));
	ver.push_back(new VoronoiPoint(-2.224999999999999645, -1.399999999999999911));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -1.000000000000000000));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -1.000000000000000000));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -0.900000000000000022));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -0.900000000000000022));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -0.800000000000000044));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -0.800000000000000044));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -0.699999999999999956));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -0.699999999999999956));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -0.599999999999999978));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -0.599999999999999978));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -0.500000000000000000));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -0.500000000000000000));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -0.399999999999999911));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -0.399999999999999911));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -0.299999999999999933));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -0.299999999999999933));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -0.199999999999999956));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -0.199999999999999956));
	ver.push_back(new VoronoiPoint(1.300000000000000044, -0.099999999999999978));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, -0.099999999999999978));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.000000000000000000));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.000000000000000000));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.100000000000000089));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.100000000000000089));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.200000000000000178));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.200000000000000178));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.300000000000000044));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.300000000000000044));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.400000000000000133));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.400000000000000133));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.500000000000000000));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.500000000000000000));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.600000000000000089));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.600000000000000089));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.700000000000000178));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.700000000000000178));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.800000000000000044));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.800000000000000044));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 0.900000000000000133));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 0.900000000000000133));
	ver.push_back(new VoronoiPoint(1.300000000000000044, 1.000000000000000000));
	ver.push_back(new VoronoiPoint(-1.300000000000000044, 1.000000000000000000));
	vdg = new Voronoi();
	double minY = -10;
	double maxY = 10;
	edges = vdg->ComputeVoronoiGraph(ver, minY, maxY);
	delete vdg;
	cout << "\t\tVoronoi Edges\n";
	for (vector<VEdge>::iterator j = edges.begin(); j != edges.end(); j++)
		cout << "(" << j->VertexA.x << ", " << j->VertexA.y << ")\t(" << j->VertexB.x << ", " << j->VertexB.y << ")\n";


	for (vector<VoronoiPoint*>::iterator i = ver.begin(); i != ver.end(); i++)
	{
		cout << "\t\tSite =  (" << (*i)->x << ", " << (*i)->y << ")\n";
		for (vector<VEdge>::iterator j = edges.begin(); j != edges.end(); j++)
		{
			if (((j->Left_Site.x == (*i)->x) && (j->Left_Site.y == (*i)->y)) || ((j->Right_Site.x == (*i)->x) && (j->Right_Site.y == (*i)->y)))
				cout << "(" << j->VertexA.x << ", " << j->VertexA.y << ")\t(" << j->VertexB.x << ", " << j->VertexB.y << ")\n";
		}
		cout << "\n";
	}
	glutInit(&argc, argv);
	glutInitWindowSize(840, 768);   // Set the window's initial width & height - non-square
	glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
	glutCreateWindow("Voronoi Diagram");  // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the infinite event-processing loop
	system("pause");
}
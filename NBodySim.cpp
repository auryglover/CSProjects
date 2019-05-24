/*Arianna Glover*/
/*Recreating Our Solar System with N-body Simulation*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>

//Hard code constant
double G = 6.67e-11;

//Creating structs for each Particle
struct Position {
	double x;
	double y;
};

struct Velocity {
	double vx;
	double vy;
};

struct Acceleration {
	double ax;
	double ay;
};

struct Force {
	double fx;
	double fy;
};

struct Particle {
	double mass;
	double x;
	double y;
	double vx;
	double vy;
	Position pos;
	Velocity vel;
};

//Functions to perform on particles
struct Force compute_force (Particle a, Particle b){
	a.pos.x = a.x;
	a.pos.y = a.y;
	b.pos.x = b.x;
	b.pos.y = b.y;

	Force f;
	Position r;
	double magr, c;

	r.x = b.pos.x - a.pos.x;
	r.y = b.pos.y - a.pos.y;

	magr = sqrt(r.x*r.x + r.y*r.y);
	c = G * a.mass * b.mass / (magr*magr*magr);
	f.fx = c * r.x;
	f.fy = c * r.y;
	return f;
}

struct Acceleration compute_acceleration (Particle a, Force f) {
	struct Acceleration acc;
	acc.ax = f.fx / a.mass;
	acc.ay = f.fy / a.mass;
	return acc;
}

struct Particle update_velocity (Particle a, Acceleration acc, int tc) {
	a.vel.vx = a.vx;
	a.vel.vy = a.vy;
	a.vel.vx = a.vx + acc.ax * tc;
	a.vel.vy = a.vy + acc.ay * tc;
	return a;
}

struct Particle update_position (Particle a, Velocity vel, int tc) {
	a.pos.x = a.x + a.vel.vx * tc;
	a.pos.y = a.y + a.vel.vy * tc;
	return a;
}

int main() {
	
	/*Reading File and Initializing Values*/
	//Particle particle[9];
	struct Particle *par;
	double m, x, y, vx, vy;
	int j=0, n;
	FILE* ptr = fopen("plant_info.txt","r");
	
	if (ptr==NULL) {
		printf("no file.");
		return 0;
	}
	fscanf(ptr, "%d\n", &n);
	par=(struct Particle *) malloc(n*sizeof(struct Particle));
	while (fscanf(ptr,"%lf,%lf,%lf,%lf,%lf\n", &m, &x, &y, &vx, &vy) != EOF) {
		(par+j)->mass=m;
		//particle[j].m = m;
		(par+j)->x=x;
		//particle[j].x = x;
		(par+j)->y=y;
		//particle[j].y = y;
		(par+j)->vx=vx;
		//particle[j].vx = vx;
		(par+j)->vy=vy;
		//particle[j].vy = vy;
		j++;
	}

	for(j=0;j<n;j++) {
		printf("%lf\n", (par+j)->vx);
	}	

	//Compute Force between two particles
	//Q how can I assign values of pointer to struct instead
	
	//std::cout << compute_force(*(par+0), *(par +1));    particle[0], particle[1]);

	free(par);
	fclose(ptr);
}

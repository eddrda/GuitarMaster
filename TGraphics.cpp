
#include "TGraphics.h"
#include <GL/gl.h>
#include <iostream>


using namespace org::toxic::graphics;
using namespace std;


TGraphics::TGraphics()
{
	alpha = 0;
}

TGraphics::~TGraphics()
{
	
}

void TGraphics::Init()
{
	//disabling z-buffering gives some extra performance
	glDisable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
	//glEnable(GL_DITHER);
	
	
	
	
}

void TGraphics::Resize(float w,float h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f,100.0f,100.0f,0.0f,0.0f,100.0f);
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
}


void TGraphics::Draw()
{
	Clear();
	
	alpha--;
	if(alpha<=-10)alpha = 0;
	glPushMatrix();
	glTranslatef(alpha,0.0f,0.0f);
	
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(i%2)
				glColor3ub(100,255,100);
			else
				glColor3ub(100,180,100);
			
			
			glBegin(GL_QUADS);
			glVertex2i(alpha+(i*10),j*20);
			glVertex2i(alpha+(i*10)+10,j*20);
			glVertex2i(alpha+(i*10)+10,(j*20)+20);
			glVertex2i(alpha+(i*10),(j*20)+20);
			
			glEnd();
			
			
		}
		
	}
	
	glPopMatrix();
	
	glColor3ub(255,0,0);
	glBegin(GL_LINES);
	glVertex2i(0,20);
	glVertex2i(100,20);
	glVertex2i(0,40);
	glVertex2i(100,40);
	glVertex2i(0,60);
	glVertex2i(100,60);
	glVertex2i(0,80);
	glVertex2i(100,80);
	
	glEnd();
	
	/*
	glTranslatef(0.0f,10.0f,0.0f);
	DrawUserFret(0);
	glTranslatef(0.0f,20.0f,0.0f);
	DrawUserFret(1);
	*/	
	
}


void TGraphics::Clear()
{
	glLoadIdentity();
	glFlush();	
	//glClearColor(0.3f,0.7f,0.3f,1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
}


void TGraphics::DrawUserFret(int color)
{
	glBegin(GL_QUADS);
	
	switch(color)
	{
		case 0:
			glColor3ub(60,255,60);
		break;
		
		case 1:
			glColor3ub(255,60,60);
		break;
	}
	
	glVertex2f(0.0f,0.0f);
	glVertex2f(8.0f,0.0f);
	glVertex2f(8.0f,8.0f);
	glVertex2f(0.0f,8.0f);
		
	
	glEnd();
}

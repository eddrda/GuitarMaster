#ifndef TGRAPHICS_H
#define TGRAPHICS_H


namespace org
{
	namespace toxic
	{
		namespace graphics
		{
			class TGraphics
			{
				
				public:
				int alpha;
				
				
				TGraphics();
				~TGraphics();
				
				void Init();
				void Resize(float w,float h);
				void Draw();
				void Clear();
				
				//game methods
				void DrawUserFret(int color);
				
				
			};
		}
	}
}


#endif

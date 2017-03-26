#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "cinder/Capture.h"
#include "cinder/Log.h"

#define PIXEL_SIZE 20

using namespace ci;
using namespace ci::app;
using namespace std;

class PixelMirrorApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    CaptureRef  mCapture;
    
    int numX, numY;
    
    std::vector<Color8u> mAveragedColors;
    std::vector<int> mThresholdValues;
    
    int threshold;
    
    Color8u getAverage(Surface* _surface, vec2 _ULvertex);
    int getValue(Surface* _surface, vec2 _ULvertex);
};

void PixelMirrorApp::setup()
{
    threshold = 128;
    
    try {
        mCapture = Capture::create(640,480);
        mCapture->start();
    } catch (CaptureExc &exc) {
        CI_LOG_EXCEPTION("failed to init camera", exc);
    }
    
    numX = mCapture->getWidth() / PIXEL_SIZE;
    numY = mCapture->getHeight() / PIXEL_SIZE;
}

void PixelMirrorApp::mouseDown( MouseEvent event )
{
}

void PixelMirrorApp::update()
{
    if (mCapture && mCapture->checkNewFrame()){
        
        mAveragedColors.clear();
        
        auto mPixels = *mCapture->getSurface();
        
        for (int i = 0; i < mPixels.getWidth(); i += PIXEL_SIZE){
            for (int j = 0; j < mPixels.getHeight(); j += PIXEL_SIZE){
                
                Color8u tempColor = getAverage(&mPixels, vec2(i,j));
                
                mAveragedColors.push_back(tempColor);
            }
        }
        
    }
}

void PixelMirrorApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    if (mAveragedColors.size() > 0){
        
        int index = 0;
        
        for (int i = 0; i < getWindowWidth(); i += PIXEL_SIZE){
            
            for (int j = 0; j < getWindowHeight(); j += PIXEL_SIZE){
                
                gl::color(Color8u(mAveragedColors[index]));
                
                Rectf rect = Rectf (vec2(i,j), vec2(i+PIXEL_SIZE, j + PIXEL_SIZE));
                
                gl::drawSolidRect(rect);
                
                index++;
                
            }
        }
        
        
        
    }
}

Color8u PixelMirrorApp::getAverage(Surface* _surface, vec2 _ULvertex)
{
    
    Area area = Area(_ULvertex.x, _ULvertex.y, _ULvertex.x + PIXEL_SIZE, _ULvertex.y + PIXEL_SIZE);
    
    int32_t sumR, sumG, sumB;
    
    sumR = 0;
    sumG = 0;
    sumB = 0;
    
    int counter = 0;
    
    Surface::Iter iter = _surface->getIter(area);
    
    while (iter.line() ) {
        while (iter.pixel() ) {
            
            sumR += (int) iter.r();
            sumG += (int) iter.g();
            sumB += (int) iter.b();
            
            counter++;
        }
    }
    
    return Color8u( sumG/counter, sumR/counter, sumB/counter);

}

CINDER_APP( PixelMirrorApp, RendererGl )


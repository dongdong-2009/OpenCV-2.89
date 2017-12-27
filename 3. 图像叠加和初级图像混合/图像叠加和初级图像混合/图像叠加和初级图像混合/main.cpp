
#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
using namespace cv;  

//利用感兴趣区域ROI实现图像叠加  
bool ROI_AddImage()  
{
    //载入图像
    Mat srcImage = imread("image/lol_pa.jpg");
    Mat logoImage = imread("image/lol_logo2.jpg");   

    //图像校验
    if ((srcImage.data == NULL) || (logoImage.data == NULL))
    {
        printf("Load Image Err!\r\n");

        //等待按键输入
        waitKey(0);

        return -1;
    }

    //设定ROI区域(兴趣区域)
    Mat imageROI = srcImage(Rect(10,10,logoImage.cols,logoImage.rows));  
    //Mat imageROI = srcImage(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));  

    //加载掩模(必须是灰度图)
    Mat mask = imread("image/lol_logo2.jpg", CV_LOAD_IMAGE_GRAYSCALE);   

    //将掩模拷贝到ROI
    logoImage.copyTo(imageROI, mask);

    //显示结果
    namedWindow("<1>利用ROI实现图像叠加示例窗口");  
    imshow("<1>利用ROI实现图像叠加示例窗口",srcImage); 

}


//初级图像混合——线性混合操作
bool LinearBlending()  
{
    //载入图像
    Mat srcImage = imread("image/mogu.jpg");
    Mat logoImage = imread("image/rain.jpg");   
    Mat dstImage;

    //图像校验
    if ((srcImage.data == NULL) || (logoImage.data == NULL))
    {
        printf("Load Image Err!\r\n");
        waitKey(0);
        return -1;
    }

    //图像混合加权操作
    double alphaValue = 0.4;
    addWeighted(srcImage, alphaValue, logoImage, (1-alphaValue), 0.0, dstImage);  

    //显示混合图
    namedWindow("<2>线性混合示例窗口【原图】", 1);  
    imshow("<2>线性混合示例窗口【原图】", srcImage );  

    namedWindow("<3>线性混合示例窗口【效果图】", 1);  
    imshow("<3>线性混合示例窗口【效果图】", dstImage );  

    return true;
}

bool ROI_LinearBlending() 
{
    //载入图像
    Mat srcImage = imread("image/lol_pa.jpg");
    Mat logoImage = imread("image/rain3.jpg");   

    //图像校验
    if ((srcImage.data == NULL) || (logoImage.data == NULL))
    {
        return -1;
    }

    //设定ROI区域(兴趣区域)
    Mat imageROI = srcImage(Rect(10,10,logoImage.cols,logoImage.rows));  

    //图像混合加权操作
    double alphaValue = 0.8;
    addWeighted(imageROI, alphaValue, logoImage, (1-alphaValue), 0.0, imageROI);  

    //显示结果
    namedWindow("<4>区域线性图像混合示例窗口");  
    imshow("<4>区域线性图像混合示例窗口",srcImage);  

    return true;  
}

bool ROI_LinearBlendingGammaTest(void)
{
    //载入图像
    Mat srcImage = imread("image/lol_pa.jpg");
    Mat RainImage = imread("image/rain3.jpg");

    //图像校验
    if ((srcImage.data == NULL) || (RainImage.data == NULL))
    {
        return -1;
    }

    //设定ROI区域(兴趣区域)
    //将雨滴跟原图混合
    Mat imageROI = srcImage(Rect(0,0,RainImage.cols,RainImage.rows));  

    //图像混合加权操作
    double alphaValue = 0.8;
    addWeighted(imageROI, alphaValue, RainImage, (1-alphaValue), 40, imageROI);  

    //显示结果
    namedWindow("<5>区域线性图像混合Gamma测试窗口");  
    imshow("<5>区域线性图像混合Gamma测试窗口",srcImage);  
}

int main(void)
{
    //ROI混合测试
    ROI_AddImage();

    //线性混合操作测试
    LinearBlending();

    //线性混合操作测试2
    ROI_LinearBlending();

    //线性混合操作测试3
    ROI_LinearBlendingGammaTest();

    //等待按键输入
    waitKey(0);

    return 0;
}




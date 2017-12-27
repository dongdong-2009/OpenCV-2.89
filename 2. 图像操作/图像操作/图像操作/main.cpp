//标配调用语句
#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
   
using namespace cv;  //OpenCV 名称空间

int main()
{

//-----------------------------------【初级图像混合】--------------------------------------  
//     描述：初级图像混合  
//-----------------------------------------------------------------------------------------------  
    //载入图像
    Mat city= imread("city.jpg");  
    Mat timo= imread("timo.jpg");  

    //载入后先显示  
    namedWindow("【2】原画图");  
    imshow("【2】原画图",city);  
   
    namedWindow("【3】logo图");  
    imshow("【3】logo图",timo);  

    //定义一个Mat类型，用于存放，图像的ROI  
    //注: 若以CV_LOAD_IMAGE_GRAYSCALE打开图像,则在以下语句中产生错误
    Mat imageROI;  
    imageROI=city(Rect(0,350,timo.cols,timo.rows)); 

    //将logo加到原图上  
    addWeighted(imageROI,0.5,timo,0.3,0.,imageROI);  

    //显示结果  
    namedWindow("【4】原画+logo图");  
    imshow("【4】原画+logo图",city);

    //输出一张jpg图片到工程目录下  
    imwrite("提莫合成.jpg",city);  

    //等待按键输入后窗口自动关闭  
    waitKey(0);  
}


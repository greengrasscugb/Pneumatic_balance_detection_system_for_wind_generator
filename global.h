#ifndef GLOBAL_H
#define GLOBAL_H
#include <string>
#include <vector>
/*所有参数的声明*/

extern std::vector<double> dataBucket;
//默认data中存储的已经是全部数据，分三类，0,1，distance
//    std::vector<int> data
extern std::vector<int> timeStamp;
//存储对应位置的时间戳

/*传感器信息传参*/
extern int rootFrequency, tipFrequency;

/*条件信息*/
extern std::string itemName, dataName;
extern double beginTime, endTime;

/*数据信息*/
extern double aAngle, bAngle;

extern double DATAHIGH;//默认存储的最大值
extern double DATALOW;//默认存储的最小值
extern double dataHigh,dataLow;//用户传入的最大值和最小值
extern std::vector<double> dataNum1;
extern std::vector<double> dataDelta1;
extern std::vector<int> dataLength;
extern double **dataNumCell;
extern double threShold;//阈值
extern double **blade1RootCell;//叶片1
extern double **blade2RootCell;//叶片2
extern double **blade3RootCell;//叶片3
extern double **blade1VibCell;//非叶片1
extern double **blade2VibCell;//非叶片2
extern double **blade3VibCell;//非叶片3
extern double teiLung1,teiLung2,teiLung3;//与预期齿间距的差值
extern double *rpm;//转速数组
extern double **blade1_root_temp;//处理过的叶片1
extern double **blade2_root_temp;//处理过的叶片2
extern double **blade3_root_temp;//处理过的叶片3
extern double *blade1_root;//将上面的3200*n的数组处理为3200*1之后得到的数组
extern double *blade2_root;
extern double *blade3_root;
extern double *blade1_root_tem;//将上面的3200*1的数组处理后的数组进行拟合后得到的数组
extern double *blade2_root_tem;
extern double *blade3_root_tem;
extern double *blade_root_tem_ave;//将上面三个3200*1的拟合后的数组求平均数之后得到的3200*1的数组

#endif  // GLOBAL_H

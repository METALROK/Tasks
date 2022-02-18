#include <iostream> 
#include <fstream> 
#include <vector>
using namespace std; 


int main(int argc, char *argv[]) {

    ifstream File(argv[1]); 

    int num = 0, compLow = 0, compHigh = 0, score = 0, size = 1, finnum;
    double aver = 0, sum = 0; 
    vector<int> nums{0};
    

    //заносим данные из файла в массив
    while (File) {
        File >> nums[num];
        if (File.eof()) break;
        nums.resize(++size); num++; 
    } 
    

    //вычисляем среднее арифметическое 
    for (int val = 0; val < size; val++) 
        sum += nums[val]; 
    aver = sum/size; //сохраняем СА в переменной aver


    //находим количество элементов, по значению больших чем СА и количество меньших
    for (int val = 0; val < size; val++) 
        if (nums[val] < aver) compLow++;
        else if (nums[val] > aver) compHigh++;


    //Находим каких элементов (больших или меньших) больше
    if (compLow < compHigh) {

        if (sizeof(aver) == 4) aver++;
        else if (sizeof(aver) == 8) aver = ceil(aver);

    } else if (compLow > compHigh) {

        if (sizeof(aver) == 4) aver--;
        else if (sizeof(aver) == 8) aver = floor(aver);

    } else { //если количество обоих типов элементов равно, число округляется (если double) или остаётся таким-же (если int)

        for (int val = 0; val < size; val++) 
            if (nums[val] == aver) finnum = aver;  
        finnum = round(aver); 

    } 
    finnum = aver; //значение присвается чилу-образцу 


    //числа массива увеличиваются или уменьшаются до числа-образца
    for (int val = 0; val < size; val++) 
        if (nums[val] > finnum) 
            while (nums[val] > finnum) {

                nums[val]--; 
                score++; //счётчик ходов

            }
        else if (nums[val] < finnum) 
            while (nums[val] < finnum) {

                nums[val]++;
                score++; 

            }
    

    cout << score; 
    return 0; 
} 
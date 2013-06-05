#include <iostream>
#include <conio.h>
using namespace std;

class tree
{
    int value;	//Значение элемента
    tree *left, *right;	// Указатели вправо и влево.
    static tree* create(int *begin, int *end, int *min, int *max)//Создаем дерево
    {
        int count=end-begin;//Проверяем на пустоту
        if(count<0)														
            return 0;													
        int n=count/2;
        int *mid=begin+n;
        tree *t=new tree(*mid);	//Создаем указатель на элемент типа "дерево"
        if(mid!=min)// Если элемент не равен минимальному, то отсылаем его налево.
        {
            t->left=create(begin, mid-1, min, max);
        }
        if(mid!=max)// Аналогично
        {
            t->right=create(mid+1, end, min, max);
        }
        return t;
    }
    void out(char* str)	// Выводим
    {
        if (left)// Если есть указатель на лево, то мы создаем строку.
        {
            char *s=new char[strlen(str)+3];
            strcpy(s, str);	// Копируем строку в переменную str
            strcat(s, "  ");											
            left->out(s);// Делаем рекурсию, чтобы в строке были все элементы.
            delete []s;	// Удаляем из памяти
        }
        cout << str << value << endl;									
        if (right)// Функция по аналогии с выводом слева.
        {
            char *s=new char[strlen(str)+3];
            strcpy(s, str);
            strcat(s, "  ");
            right->out(s);
            delete []s;
        }
    }
public:
    tree(int val)// Начальная инициализация элементов
    {
        value=val;
        left=0;
        right=0;
    }
    static tree* create(int* begin, int* end)					
    {
        return create(begin, end, begin, end);
    }
    void out()													
    {
        out("");
    }
};
int *array;
tree* tr;



int main()													
{
    int len, a;	// объявление переменной кол-ва элементов и удаляемого в будущем элемента
    cout<<"Enter the number of elements: ";
    cin>>len;
    array=new int[len];
    for(int i=0;i<len;i++)// Создание динамического массива и его инициализация.
    {
        cout<<"Enter the value of element #"<<i+1<<": ";
        cin>>array[i];
    }
	tr=tree::create(array, array+len-1);// Заполнение дерева функцией create
    tr->out();// Вывод получившегося дерева
	delete tr;// Очищение дерева
	cout<<"Enter delete elem:"<<endl;
	cin>>a;	//Вводим элемент на удаление
	 for(int i=0;i<len;i++)
    {
        if(array[i]==a)	//Заменяем его на 0
			array[i]=0;
    }
	cout<<"Tree without this elem "<<a<<":"<<endl;
	tr=tree::create(array, array+len-1);// Снова заполняем дерево
    tr->out();// Выводим получившееся. 
    getch();
    delete[] array;
}
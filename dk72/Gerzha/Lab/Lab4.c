#include <stdio.h>
#include <stdlib.h>

typedef struct c_list
{
	int inf;	// поле данных
	struct c_list *next;	// указатель на следующий элемент
	struct c_list *prev;	// указатель на предыдущий элемент
} clist;


clist *cir_lst;
int is_init = 0;
int amount = 0;

void GetList();
int GetElem();
int GetVal();
void ProcList();
int ListDeletElem(clist *lst);
void ListOutput();
clist *ListInit(int val);
void ListAddElem(int val);


int main()
{
	GetList();
	ProcList();
}

void GetList()
{
	printf("Введите элементы циклического списка, разделяя их с помощью клавишы Enter.\n");
	printf("Элементами списка могут быть только натуральные числа.\n");
	printf("Для прекращенния добавления элементов введите -1\n");
	while (GetElem()){	}
	printf("Ваш список:\n");
	ListOutput();
	printf("\n");
	printf("-----------------------------------\n");
}

int GetElem()
{
	int val;
	val = GetVal();
	while (val != -1){					// пока не конец ввода

		if (!is_init) {					// если список не инициализирован
			cir_lst = ListInit(val);	// иницциализируем список
			amount++;					// прибавляем количество элементов
		}
		else {
			ListAddElem(val);			// добавляем элемент в список
			amount++;					// прибавляем количество элементов
		}
		val = GetVal();
	}

	if (amount == 0) {					// если нету ни одного элемента
		printf("Вы не ввели ни одного элемента. Попытайтесь еще раз.\n");
		return 1;
	}
	return 0;
}

int GetVal()	// получение числа с проверкой на правильность ввода
{
	int val;
	int chek;
	chek = scanf("%d", &val);
	while(chek == 0 || val < -1) {
		printf("Неверный формат ввода. Попытайтесь еще раз.\n");
		getchar();
		chek = scanf("%d", &val);
	}

	return val;
}

void ProcList()			// обработка списка
{
	int val;
	clist *lst;
	lst = cir_lst;		// смещаем указатель на третий элемент
	lst = lst->next;
	lst = lst->next;
	while (amount >= 3) {		// пока количетво элементов больше равно 3
		if (lst == cir_lst) {	// если нужно удалить начало списка то сдвигаем его
			cir_lst = cir_lst->next;
		}
		val = ListDeletElem(lst);	// удаляем элемент

		amount--;
		printf("Удаление єлемента: %d\n", val);
		printf("Состояние списка:\n");
		ListOutput();				// вывод списка
		printf("\n");
		lst = lst->next;			// смещаем указатель на 3 позиции
		lst = lst->next;
		lst = lst->next;
	}
	printf("-----------------------------------\n");
	printf("Окончательный состояние списка:\n");
	ListOutput();					// вывод списка
	printf("\n");
}

clist *ListInit(int val)  // val значение первого узла
{
	clist *lst;	// выделение памяти под корень списка
	lst = (clist*)malloc(sizeof(clist));
	lst->inf = val;	// заполнаем узел значением val
	lst->next = lst; // указатель на следующий узел
	lst->prev = lst; // указатель на предыдущий узел
	is_init = 1;
	return lst;
}


void ListAddElem(int val)
{
	clist *temp, *p, *lst;
	lst = cir_lst->prev;	 // смещение указателя на предыдущий элемент
							 // для добавление нового элементов последовательно
	temp = (clist*)malloc(sizeof(clist));
	p = lst->next;	// сохранение указателя на следующий узел
	lst->next = temp;	// предыдущий узел указывает на создаваемый
	temp->inf = val; // сохранение поля данных добавляемого узла
	temp->next = p;	// созданный узел указывает на следующий узел
	temp->prev = lst;	// созданный узел указывает на предыдущий узел
	p->prev = temp;
	}

int ListDeletElem(clist *lst)
{
	int val;
	clist *prev, *next;
	val = lst->inf;
	prev = lst->prev; // узел, предшествующий lst
	next = lst->next; // узел, следующий за lst
	prev->next = lst->next; // переставляем указатель
	next->prev = lst->prev; // переставляем указатель
	free(lst); 		// освобождаем память удаляемого элемента
	return val;
}

void ListOutput()
{
	clist *p;
	p = cir_lst;
	do {
	printf("%d ", p->inf);	// вывод значения элемента p
	p = p->next;			// переход к следующему узлу
	} while (p != cir_lst);	// условие окончания обхода
}
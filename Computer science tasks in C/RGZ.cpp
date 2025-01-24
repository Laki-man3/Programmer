#include <stdio.h>

unsigned Z(unsigned k) //выделяем знак
{
	k >>= 31;
	return k;
}

unsigned M(unsigned k) { // выделяем мантису
	k <<= 9; // 9 = 1 бит знак + 8 бит характеристика
	k >>= 9;
	k = k | 040000000; // добавляет 1, которая не хранится в числе для экономии разрядов
	return k;
}

unsigned H(unsigned k) //выделяем характеристику
{
	k <<= 1; // убираем бит отвечающий за знак
	k >>= 1;
	k >>= 23; // кол-во бит в мантиссе 32 - 9
	return k;
}

unsigned dec2bin(unsigned num) // перевод десятичное num в бинарный вид (двоичный вид)
{
	unsigned bin = 0, k = 1;

	while (num > 0)
	{
		bin += (num % 2) * k;
		k *= 10;
		num /= 2;
	}
	return bin;
}

void Binary(unsigned x) // безнаковое целое в масс в двоич
{
	int i; char a[32];
	for (i = 0; i < 32; i++)
	{
		a[i] = x % 2;
		x = x / 2;
	}
	for (i = 22; i >= 0; i--)
		printf("%d", a[i]);
}

void int_dec2bin(int num) // перевод из десятичного в двоичное целого, массив для того чтобы перевернуть двоичную запись
{
	int a, i, mass[99];
	for (i = 0; i < 99; i++)
	{
		mass[i] = 0;
	}
	a = num;
	if (a == 0)
		printf("%d", 0);
	i = 0;
	while (a != 0)
	{
		if (a % 2 == 0)
		{
			mass[i] = 0;
			a = a / 2;
		}
		else
		{
			mass[i] = 1;
			a = a / 2;
		}
		i++;
	}
	i = i - 1;
	for (; i >= 0; i--)
		printf("%d", mass[i]);
}

void int_float2bin(double num) // переводим дробное из десятичного в двоичный
{
	int d = num;
	double f = num - d;

	while (f)
	{
		d = f * 2;
		if (d >= 1)
			f = f * 2 - d;
		else f *= 2;

		printf("%d", d);
	}
}

unsigned cel(unsigned long long k, int p) // p - порядок, определяем целую часть по мантиссе
{
	p -= 127;
	unsigned long long a = 23 - p;
	k >>= a;
	return k;
}

unsigned drob(unsigned long long k, int p) // определяем дробную часть по мантиссе
{
	unsigned long long b = k;
	p -= 127;
	k <<= 41 + p; // 41=9+32. 9 характеристика и знак 32 бита не нужных (long long имеет 64 бита
	k >>= 41 + p;
	return k;
}
/* Переведем дробную часть двоичного числа в десятичный вид.
Для этого число необходимо умножать на 10.

Выделяем дробную и целую часть и продолжаем процесс пока дробная часть не
станет равной нулю.*/
void desyat(unsigned long long k, int p)
{
	unsigned long long b = k;
	p -= 127;
	b >>= 23 - p;
	k <<= 41 + p;
	k >>= 41 + p;
	while (k != 0)
	{
		k = k * 10;
		unsigned long long a = k;
		a >>= 23 - p;
		printf("%ld", a);
		k <<= 41 + p;
		k >>= 41 + p;
	}
}


int main()
{
	union // объединяем для записи в одну ячейку памяти
	{
		unsigned k; // тип unsigned int
		float fk; //тип Float
	} a;

	printf("Number:"); scanf_s("%f", &a.fk); // ввод числа
	printf("Number in bin: %d %d ", Z(a.k), dec2bin(H(a.k))); Binary(M(a.k)); // число в машинном коде
	printf("\n\nCharacteristics: %d", dec2bin(H(a.k))); // характеристика
	printf("\n\nOrder: %d", H(a.k) - 127); // порядок
	printf("\n\nMantissa: "); Binary(M(a.k)); // мантисса
	printf("\n\nInteger part in bin: "); int_dec2bin(a.fk);// целое в двоичном
	printf("\n\nFloat part in dec: 0."); int_float2bin(a.fk); // дробное в двоичном
	printf("\n\nInteger part in dec: %d", cel(M(a.k), H(a.k))); // в десятичном
	printf("\n\nFloat part in dec: 0."); desyat(drob(M(a.k), H(a.k)), H(a.k)); // в двоичном
	printf("\n\nNumber in dec: %d.", cel(M(a.k), H(a.k))); desyat(drob(M(a.k), H(a.k)), H(a.k)); // число в десятичном
}
#include <iostream>
#include <string>

class Person 
{
private:
	std::string name;
	int age;
public:
	//контсруктор по умолчанию всегда с пустыми скобками
	Person()
	{
		name = "noname";
		age = 18;
	}
	//параметрический конструктор
	Person(std::string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	//конструктор копирования
	Person(const Person& other)
	{
		name = other.name;
		age = other.age;
	}
	//дeструктор
	~Person()
	{
		std::cout << name << "Уничтожено\n";
	}
	void introduce() //
	{
		std::cout << "My name is " << name << std::endl;
	}
	//сеттер заменить
	void setName(std::string name)
	{
		this->name = name;
	}
	//геттер возврат значения
	std::string getName()
	{
		return name;
	}
};
// создаем доп класс для наследования
class Student : public Person
{
protected:
	std::string group;
	int grades_number;
	int* grades;
public:
	Student() : Person()
	{
		group = "undefined";
		grades = nullptr;
		grades_number = 0;
	}
	Student(std::string name, int age, std::string group, int grades[], int grades_number) : Person(name, age)
	{
		this->group = group;
		this->grades = new int[grades_number] {};
		for (int i = 0; i < grades_number; i++)
			this->grades[i] = grades[i];
		this->grades_number = grades_number;
	}
	~Student() //дeструктор применяется в основном для освобождения памяти
	{
		delete[] grades;
	}
	void printGrades() //функция для вывода
	{
		for (int i = 0; i < grades_number; i++)
		{
			std::cout << grades[i] << ' ';
		}
		std::cout << std::endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//осздание объекта класса
	
	Person p1("Bob ", 25);
	p1.introduce();

	if (true)
	{
		Person tmp("Mike", 50);
		tmp.introduce();
	}

	Person p2(p1);
	p2.setName("Sara ");
	p2.introduce(); //пердедача данных первого второму пользователю

	std::cout << "Имя объекта:" << p2.getName() << std::endl;
	

	//работа с классом наследником
	int grades[3]{ 10,12,9 };
	Student s1("Rodion ", 20, "Бв322", grades, 3);
	s1.introduce();
	s1.printGrades();
	

	return 0;
}
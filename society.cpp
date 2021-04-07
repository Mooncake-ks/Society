#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <list>

class Human
{
public:
	Human();
	Human(std::string name, std::string surname, std::string age);
	Human(const std::initializer_list<std::string>& list);
	void set_name(std::string name);
	void set_surname(std::string surname);
	void set_age(std::string age);
	std::string get_name()const;
	std::string get_surname()const;
	std::string get_age()const;
private:
	std::string name, surname, age;
};
class Student: public Human
{
public:
	Student(int group, std::vector<int> ratings);
	Student(int group, std::vector<int> ratings, std::string name, std::string surname, std::string age);
	void set_group(int group);
	void set_ratings(std::vector<int>ratings);
	int get_group()const;
	std::vector<int> get_ratings()const;
	double average_score()const;
	friend std::ostream& operator << (std::ostream& os, const Student& p);
	friend std::istream& operator >> (std::istream& in, Student& p);
private:
	int group;
	std::vector<int>ratings;
};
class Teacher:public Human
{
public:
	Teacher(int working_hours);
	Teacher(int working_hours, std::string name, std::string surname, std::string age);
	void set_working_hours(int working_hours);
	int get_working_hours()const;
	friend std::ostream& operator << (std::ostream& os, const Teacher& p);
	friend std::istream& operator >> (std::istream& in, Teacher& p);
private:
	int working_hours;
};
int main()
{
	std::vector<int> rating = {5,5,3,4,4};
	std::string name = "Blake";
	std::string surname = "Stone";
	std::string age = "23";
	Human A{ "Sophie","Morris","18" };
	Student B(239,rating,name,surname,age);
	Student B2(455,rating);
	std::cin >> B2;
	Teacher C(240,"Noah","Stafford","27");
	std::cout <<"Students :\n"<< B<<"\n" << B2<<"Teacher :\n" << C << std::endl;
	system("pause");
	return 0;
}
Human::Human() :name{ " None " }, surname{ " None " }, age{ " None " }{}
Human::Human(std::string name, std::string surname, std::string age):name{name},surname{surname},age{age}{}
Human::Human(const std::initializer_list<std::string>& list)
{
	int size = list.size();
	int i = 0;
	std::string* test = new std::string[size];
	for ( auto iter = list.begin(); iter != list.end(); iter++)
	{
		test[i] = *iter;
		i++;
	}
	set_name(test[0]);
	set_surname(test[1]); //Доделать и пределать 
	set_age(test[2]);
}
void Human::set_name(std::string name)
{
	this->name = name;
}
void Human::set_surname(std::string surname)
{
	this->surname = surname;
}
void Human::set_age(std::string age)
{
	this->age = age;
}
std::string Human::get_name()const
{
	return std::string(name);
}
std::string Human::get_surname()const
{
	return std::string(surname);
}
std::string Human::get_age()const
{
	return std::string(age);
}

Student::Student(int group, std::vector<int> ratings)
{
	this->group = group;
	int size = ratings.size();
	for (int i = 0; i < size; i++)
	{
		this->ratings.push_back(ratings[i]);
	}
}
Student::Student(int group, std::vector<int> ratings, std::string name, std::string surname, std::string age) :Human(name,surname, age)
{
	this->group = group;
	int size = ratings.size();
	for (int i = 0; i < size; i++)
	{
		this->ratings.push_back(ratings[i]);
	}
}
void Student::set_group(int group)
{
	this->group = group;
}
void Student::set_ratings(std::vector<int> ratings)
{
	int size = ratings.size();
	for (int i = 0; i < size; i++)
	{
		this->ratings.push_back(ratings[i]);
	}
}
int Student::get_group()const
{
	return group;
}
std::vector<int> Student::get_ratings()const
{
	return std::vector<int>(ratings);
}
double Student::average_score()const
{
	double size = ratings.size();
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += ratings[i];
	}
	return sum / size;
}
std::ostream& operator<<(std::ostream& os, const Student& p)
{
	return os << "Name :" << p.get_name() << "\nSurname :" << p.get_surname() << "\nAge :" << p.get_age() << "\nGroup :" << p.get_group() << "\nAverage score :" << p.average_score() << std::endl;
}
std::istream& operator>>(std::istream& in, Student& p)
{
	std::string name,surname,age;
	in >> name>>surname>>age;
	p.set_name(name);
	p.set_surname(surname);
	p.set_age(age);
	return in;
}

Teacher::Teacher(int working_hours):working_hours{ working_hours }{}
Teacher::Teacher(int working_hours, std::string name, std::string surname, std::string age) :Human(name, surname, age), working_hours{ working_hours }{}
void Teacher::set_working_hours(int working_hours)
{
	this->working_hours = working_hours;
}
int Teacher::get_working_hours()const
{
	return working_hours;
}
std::ostream& operator<<(std::ostream& os, const Teacher& p)
{
	return os << "Name :" << p.get_name() << "\nSurname :" << p.get_surname() << "\nAge :" << p.get_age() << "\nWorking_hours :"<<p.get_working_hours() << std::endl;
}
std::istream& operator>>(std::istream& in, Teacher& p)
{
	std::string name, surname, age;
	in >> name >> surname >> age;
	p.set_name(name);
	p.set_surname(surname);
	p.set_age(age);
	return in;
}

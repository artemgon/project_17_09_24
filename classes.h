#define _CRT_SECURE_NO_WARNINGS

#include "libs.h"

class Person
{
private:
	char* s_n_p;
public:
	Person(const char* u_snp = "Unknown")
	{
		if (u_snp != nullptr) {
			s_n_p = new char[strlen(u_snp) + 1];
			strcpy(s_n_p, u_snp);
		}
	}
	Person(const Person& person1)
	{

		s_n_p = new char[strlen(person1.s_n_p) + 1];
		strcpy(s_n_p, person1.s_n_p);
	}
	const char* getSNP() const
	{
		return s_n_p;
	}
	void setSNP(const char* snp_1)
	{
		delete[] s_n_p; 
		s_n_p = new char[strlen(snp_1) + 1]; 
		strcpy(s_n_p, snp_1);
	}
	void printFunc() const {
		cout << "Person's full name(SNP): " << s_n_p << endl;
	}
	~Person()
	{
		delete[] s_n_p;
	}
};

class Flat
{
private:
	Person* people;
	int p_qty;
public:
	Flat(int qty = 0) : p_qty(qty)
	{
		if (p_qty > 0) {
			people = new Person[p_qty];
		}
		else {
			people = nullptr;
		}
	}
	Flat(const Flat& flat1) : p_qty(flat1.p_qty)
	{
		people = new Person[p_qty];
		for (int i = 0; i < p_qty; i++)
			*(people + i) = flat1.people[i];
	}
	void addPFunc(const Person& person1, int index)
	{
		if (index >= 0 && index < p_qty) {
			people[index] = person1;
		}
		else {
			cout << "Error occurred... Chose normal index..." << endl;
		}
	}
	void printFunc() const
	{
		cout << "There are " << p_qty << " people in the flat: " << endl;
		for (int i = 0; i < p_qty; i++)
		{
			people[i].printFunc();
		}
	}
	~Flat() {
		delete[] people;
	}
};

class MDU
{
	Flat* flats;
	int f_qty;
public:
	MDU(int qty = 0) : f_qty(qty)
	{
		if (f_qty > 0) {
			flats = new Flat[f_qty];
		}
		else {
			flats = nullptr;
		}
	}
	MDU(const MDU& MDU1) : f_qty(MDU1.f_qty)
	{
		flats = new Flat[f_qty];
		for (int i = 0; i < f_qty; i++)
		{
			flats[i] = MDU1.flats[i];
		}
	}
	void addFFunc(const Flat& flat, int index)
	{
		if (index >= 0 && index < f_qty) {
			flats[index] = flat;
		}
		else {
			cout << "Error occurred... Chose normal index..." << endl;
		}
	}
	void printFunc() const
	{
		cout << "There are " << f_qty << " flats in MDU:" << endl;
		for (int i = 0; i < f_qty; i++)
		{
			cout << "Flat " << i + 1 << ":" << endl;
			flats[i].printFunc();
		}
	}
	~MDU()
	{
		delete[] flats;
	}
};
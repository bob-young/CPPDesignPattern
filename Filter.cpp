//
// Created by xidian on 18-6-11.
//

#include <iostream>
#include "Filter.h"

Student::Student(std::string name, char sex, int score) {
    this->name=name;
    this->sex=sex;
    this->score=score;
}

bool Student::operator==(const Student &s1) {
    if(s1.name==name && s1.sex==sex && score==s1.score){
        return true;
    }
    return false;
}

std::vector<Student*> *Class::getmembers() {
    return this->members;
}

void Class::setmembers(std::vector<Student*> students) {
    this->members=new std::vector<Student*>(students);
}

void Class::setmembers(Class *c) {
    this->members=new std::vector<Student*>(*(c->members));
}

void MaleInClass::setmembers(std::vector<Student*> students) {
    for(int i=0;i<students.size();i++){
        if(students[i]->sex=='M'){
            this->members->push_back(students[i]);
        }
    }
}

void MaleInClass::setmembers(Class *c) {
    for(int i=0;i<c->members->size();i++){
        if((*(c->members))[i]->sex=='M'){
            this->members->push_back((*(c->members))[i]);
        }
    }
}

std::vector<Student*> *MaleInClass::getmembers() {
    return this->members;
}

void FemaleInClass::setmembers(std::vector<Student*> students) {
    for(int i=0;i<students.size();i++){
        if(students[i]->sex=='F'){
            this->members->push_back(students[i]);
        }
    }
}

void FemaleInClass::setmembers(Class *c) {
    for(int i=0;i<c->members->size();i++){
        if((*(c->members))[i]->sex=='F'){
            this->members->push_back((*(c->members))[i]);
        }
    }
}

std::vector<Student*> *FemaleInClass::getmembers() {
    return this->members;
}

void TopStudentsInClass::setmembers(std::vector<Student*> students) {
    for(int i=0;i<students.size();i++){
        if(students[i]->score>90){
            this->members->push_back(students[i]);
        }
    }
}

void TopStudentsInClass::setmembers(Class *c) {
    for(int i=0;i<c->members->size();i++){
        if((*(c->members))[i]->score>90){
            this->members->push_back((*(c->members))[i]);
        }
    }
}

std::vector<Student*> *TopStudentsInClass::getmembers() {
    return this->members;
}

AandBinClass::AandBinClass(Class *a, Class *b) {
    for(int i=0;i<a->members->size();i++){
        for(int j=0;j<b->members->size();j++){
            if((*(a->members))[i] ==(*(b->members))[j]){
                members->push_back((*(a->members))[i] );
                break;
            }
        }
    }
}

std::vector<Student*> *AandBinClass::getmembers() {
    return this->members;
}
void showMember(std::vector<Student*> *s){
    for(int i=0;i<s->size();i++){
        std::cout<<(*s)[i]->name<<"\t";
    }
    std::cout<<std::endl;

}
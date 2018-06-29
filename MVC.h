//
// Created by xidian on 18-6-29.
//

#ifndef DESIGNPATTERN_MVC_H
#define DESIGNPATTERN_MVC_H

#include <iostream>
#include <string>

namespace MVC {
    struct StudentInfo{
        int age;
        std::string name;
        int grade;
        char sex;
    };

    class StudentModel{

    public:
        StudentInfo studentInfo;
        StudentModel(StudentInfo studentInfo);
    };

    class StudentView{
    public:
        void showInfo(StudentInfo* studentInfo);
    };

    class StudentControl{
        StudentView* view;
        StudentModel* student;
    public:
        StudentControl(StudentModel* studentModel,StudentView* studentView);
        ~StudentControl();
        void upgrade();
        std::string getName();
        void Display();
    };
};


#endif //DESIGNPATTERN_MVC_H

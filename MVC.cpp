//
// Created by xidian on 18-6-29.
//

#include "MVC.h"

MVC::StudentModel::StudentModel(MVC::StudentInfo studentInfo) {
    this->studentInfo=studentInfo;

}

void MVC::StudentView::showInfo(MVC::StudentInfo *studentInfo) {
    std::cout<<"Grade:"<<studentInfo->grade<<"\tName:"<<studentInfo->name\
                      <<"\tGender:"<<studentInfo->sex\
                        <<"\tage:"<<studentInfo->age<<std::endl;

}

MVC::StudentControl::StudentControl(MVC::StudentModel *studentModel, MVC::StudentView *studentView) {
    this->student=studentModel;
    this->view=studentView;

}

MVC::StudentControl::~StudentControl() {

}

void MVC::StudentControl::upgrade() {
    this->student->studentInfo.grade++;
}

std::string MVC::StudentControl::getName() {
    return this->student->studentInfo.name;
}

void MVC::StudentControl::Display() {
    this->view->showInfo(&(this->student->studentInfo));

}

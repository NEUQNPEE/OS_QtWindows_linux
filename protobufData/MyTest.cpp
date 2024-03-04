#include "MyTest.h"
#include "t1.pb.h"
#include <QDebug>

void MyTest::test()
{
    // 序列化
    Student student;
    student.set_name("张三");
    student.set_age(20);
    student.set_subjects("数学");

    std::string output;
    
    student.SerializeToString(&output);

    // 反序列化
    Student student2;
    student2.ParseFromString(output);
    
    // 将字符串转换为QString
    QString name = QString::fromStdString(student2.name());
    QString subjects = QString::fromStdString(student2.subjects());

    qDebug() << "name: " << name;
    qDebug() << "age: " << student2.age();
    qDebug() << "subjects: " << subjects;
}
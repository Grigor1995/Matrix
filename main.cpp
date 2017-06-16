#include "matrix.h"
#include <stdlib.h>
int main()
{
	system ("CLS");
    mtx::Matrix<int> mat1(5,5);
    for (size_t i = 0;i < 5;++i)
        for (size_t j = 0;j < 5;++j)
          mat1[i][j] = int(((i+1)*(j + 1))*(j + 1));
    mtx::Matrix<int> mat2(5,5);
    for (size_t i = 0;i < 5;++i)
        for (size_t j = 0;j < 5;++j)
            mat2[i][j] = int (i + 7)*(j + 15);
	std::cout<<"\n\n\tMAT1 "<<std::endl;
	mat1.print();
	std::cout<<"\n\n\tMAT2"<<std::endl;
	mat2.print();
	mtx::Matrix<int> mat3 = mat1 + mat2;
	std::cout<<"\n\n\t MAT3 = MAT1 + MAT2"<<std::endl;
	mat3.print();
	mtx::Matrix<int> mat4 = mat1 - mat2;
	std::cout<<"\n\n\tMAT4 = MAT1 - MAT2"<<std::endl;
	mat4.print();
	mtx::Matrix<int> mat5 = mat1 * mat2;
	std::cout<<"\n\n\tMAT5 = MAT1 * MAT2"<<std::endl;
	mat5.print();
	mat3 += mat1;
	std::cout<<"\n\n\tMAT3 += MAT1"<<std::endl;
	mat3.print();
	mat4 -= mat2;
	std::cout<<"\n\n\tMAT4 -= MAT2"<<std::endl;
	mat4.print();
	mat5 *= mat1;
	std::cout<<"\n\n\tMAT5 *= MAT1"<<std::endl;
	mat5.print();
	std::cout<<"\n\n\t\tEND\n\n"<<std::endl;
	mat5 += 100;
	std::cout<<"\n\n\tMAT5 *= MAT1"<<std::endl;
	mat5.print();
	mat5 *= 10;
	std::cout<<"\n\n\tMAT5 *= MAT1"<<std::endl;
	mat5.print();
	mat5 -= 1000;
	std::cout<<"\n\n\tMAT5 *= MAT1"<<std::endl;
	mat5.print();
	mat5 /= 10;
	std::cout<<"\n\n\tMAT5 *= MAT1"<<std::endl;
	mat5.print();
	mat1 = mat5.transpose();
	std::cout<<"\n\n\tMAT5 *= MAT1"<<std::endl;
	mat1.print();
	mat5.tran();
	std::cout<<"\n\n\tMAT5 *= MAT1"<<std::endl;
	mat5.print();
	std::cout<<"\n\n\n"<<std::endl;
	mtx::Matrix<int>::vector tmp2(mat5.get_column(3));
	for (size_t i = 0;i < tmp2.size();++i)
        std::cout<<tmp2[i]<<std::endl;
    std::cout<<"\n\n"<<std::endl;
	system ("pause");
	return 0;
}

#ifndef _matrix_h_
#define _matrix_h_

#include <vector>
#include <iostream>
#include <tr1/memory>
namespace mtx
{
    template <typename T>
    class Matrix
    {
    //Typedef for values and containers
        //Container
            typedef T value_type;
            typedef std::vector<value_type> row_type;
            typedef std::vector<row_type>   container_type;
    public:
    //Constructors

        struct vector
        {
            //constructors vector struck
                vector (container_type & = 0,size_t  = 0, bool = false);
                vector(const vector & );
            //operator
                T& operator [](const size_t );
            //function return size vector object
                size_t size();
            //function return 1 if vector object is row type 0 if vector object is column type
                bool vec_val ();

            private:
                container_type & m_container;
                size_t m_index;
                bool bRow;
        };

        Matrix(size_t = 0,size_t = 0);

        Matrix (const row_type &);

        Matrix (const container_type &);

        Matrix (const Matrix &);

    //get_values functions
        vector get_row (const size_t &);

        const vector & get_row (const size_t & ) const;

        vector get_column (const size_t & );

        const vector & get_column (const size_t & ) const;

    //transpose  functions
        Matrix transpose ();

        void tran();
    //get_size functions for returning size row and column
        const size_t get_number_of_rows () const;

        const size_t get_number_of_columns () const;

    //operator overloading
        //addition operators
        Matrix operator + (const Matrix &);

        Matrix operator += (const Matrix &);

        Matrix operator + (const T &);

        Matrix operator += (const T&);

        //subtraction operators
        Matrix operator - (const Matrix & );

        Matrix operator -= (const Matrix & );

        Matrix operator - (const T &);

        Matrix operator -= (const T &);
        //multiplication operators
        Matrix operator * (const Matrix & );

        Matrix operator *= (const Matrix & );

        Matrix operator * (const T & );

        Matrix operator *= (const T & );

        //division operator
        Matrix operator / (const T & );

        Matrix operator /= (const T & );

        //assignment operator
        Matrix operator = (const Matrix & );

        Matrix operator = (const row_type &);

        Matrix operator = (const vector &);


        //Compare operators
        bool operator == (const Matrix & );

        bool operator != (const Matrix & );

        //indexing operators
        row_type & operator [] (const size_t & );

        const row_type& operator [] (const size_t & index) const;

    //Print This Matrix
        void print ()const;

        vector get_row1();
    private:
        container_type container;
        row_type invalide_row;
        value_type invalide_value;


    };
    //CONSTRUCTRORS MATRIX CLASS
    template <typename T>
    typename Matrix<T>::vector Matrix<T>::get_row1()
    {
        Matrix<T> tmp(6,5);
        for (size_t i = 0;i < 5;++i)
            for (size_t j = 0;j < 6;++j)
                tmp[i][j] = (i+18)*(j - 2);
        tmp.print();
        return tmp.get_row(3);
    }

    template <typename T>
    Matrix<T>::Matrix(size_t row,size_t column):container(row)
    {
        row_type temp1(column,0);
        for (size_t i = 0;i < row;++i)
            container[i] = temp1;
    }

    template <typename T>
    Matrix<T>::Matrix (const row_type & obj)
    {
        container.push_back(obj);
    }

    template <typename T>
    Matrix<T>::Matrix (const container_type & obj):container(obj)
    {

    }

    template <typename T>
    Matrix<T>::Matrix (const Matrix & obj):container(obj.container)
    {

    }


    //function for returning matrix size
    template <typename T>
    const size_t Matrix<T>::get_number_of_rows () const
    {
        return container.size();
    }

    template <typename T>
    const size_t Matrix<T>::get_number_of_columns () const
    {
        if (container.empty())
            return 0;
        return container.front().size();
    }

    //transpose  functions
    template <typename T>
    Matrix<T> Matrix<T>::transpose()
    {
        const size_t row_size = get_number_of_rows();
        const size_t column_size = get_number_of_columns();
        Matrix<T> tmp(column_size,row_size);
        for (size_t i = 0;i < row_size;++i)
            for (size_t j = 0;j < column_size;++j)
                tmp[j][i] = container[i][j];
        return tmp;
    }

    template <typename T>
    void Matrix<T>::tran()
    {
        const size_t row_size = get_number_of_rows();
        const size_t column_size = get_number_of_columns();
        Matrix<T> tmp(column_size,row_size);
        for (size_t i = 0;i < row_size;++i)
            for (size_t j = 0;j < column_size;++j)
                tmp[j][i] = container[i][j];
        container = tmp.container;
    }

    //get_row and get_column functions
    template <typename T>
    typename Matrix<T>::vector Matrix<T>::get_row (const size_t & index)
    {
        const size_t size_row = get_number_of_rows ();
        if (!(index < size_row))
        {
            std::cout<<"Invalid row number"<<std::endl;
            return vector(container,index,true); //testing
        }
        return vector(container,index,true);
    }

    template <typename T>
    const typename Matrix<T>::vector & Matrix<T>::get_row (const size_t & index)const
    {
        const size_t size_row = get_number_of_rows ();
        if (!(index < size_row))
        {
            std::cout<<"Invalid row number"<<std::endl;
            return vector(container,index,true); //testing
        }
        return vector(container,index,true);
    }

    template <typename T>
    typename Matrix<T>::vector Matrix<T>::get_column (const size_t & index)
    {
        const size_t size_column = get_number_of_columns();
        if (!(index < size_column))
        {
            std::cout<<"Invalid column number"<<std::endl;
            return vector(container,index);//testing
        }
        return vector(container,index);
    }

    template <typename T>
    const typename Matrix<T>::vector & Matrix<T>::get_column (const size_t & index) const
    {
        const size_t size_column = get_number_of_columns();
        if (!(index < size_column))
        {
            std::cout<<"Invalid column number"<<std::endl;
            return vector(container,index);//testing
        }

        return vector(container,index);
    }
//Operator overloading
    //addition operators
    template <typename T>
    Matrix<T> Matrix<T>::operator + (const Matrix<T> & obj)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        Matrix<T> tmp(size_row,size_column);
        if (obj.get_number_of_rows() != size_row || obj.get_number_of_columns() != size_column)
        {
            std::cout<<"Impossible to do addition operator"<<std::endl;
            return tmp;
        }
        for (size_t i = 0;i < size_row;++i)
        {
            for (size_t j = 0;j < size_column;++j)
            {
                tmp.container[i][j] = obj.container[i][j] + container[i][j];
            }
        }
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator += (const Matrix<T> & obj)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        if (obj.get_number_of_rows() != size_row || obj.get_number_of_columns() != size_column)
        {
            std::cout<<"Impossible to do addition operator"<<std::endl;
            return container;
        }
        for (size_t i = 0;i < size_row;++i)
        {
            for (size_t j = 0;j < size_column;++j)
            {
                container[i][j] += obj.container[i][j];
            }
        }
        return container;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator + (const T & value)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        Matrix<T> tmp(size_row,size_column);
        for (size_t i = 0;i < size_row;++i)
        {
            for (size_t j = 0;j < size_column;++j)
            {
                tmp.container[i][j] = value + container[i][j];
            }
        }
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator += (const T & value)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        for (size_t i = 0;i < size_row;++i)
        {
            for (size_t j = 0;j < size_column;++j)
            {
                container[i][j] += value;
            }
        }
        return container;

    }

    //subtraction operators
    template <typename T>
    Matrix<T> Matrix<T>::operator - (const Matrix<T> & obj )
    {

        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        Matrix<T> tmp(size_row,size_column);
        if (obj.get_number_of_rows() != size_row || obj.get_number_of_columns() != size_column)
        {
            std::cout<<"Impossible to do addition operator"<<std::endl;
            return tmp;
        }
        for (size_t i = 0;i < size_row;++i)
        {
            for (size_t j = 0;j < size_column;++j)
            {
                tmp.container[i][j] = container[i][j] - obj.container[i][j];
            }
        }
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator -= (const Matrix<T> & obj)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        if (obj.get_number_of_rows() != size_row || obj.get_number_of_columns() != size_column)
        {
            std::cout<<"Impossible to do addition operator"<<std::endl;
            return container;
        }
        for (size_t i = 0;i < size_row;++i)
        {
            for (size_t j = 0;j < size_column;++j)
            {
                container[i][j] =container[i][j] - obj.container[i][j];
            }
        }
        return container;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator - (const T & value)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        Matrix<T> tmp(size_row,size_column);
        for (size_t i = 0;i < size_row;++i)
        {
            for (size_t j = 0;j < size_column;++j)
            {
                tmp.container[i][j] = container[i][j] - value;
            }
        }
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator -= (const T & value)
    {


        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        for (size_t i = 0;i < size_row;++i)
        {
            for (size_t j = 0;j < size_column;++j)
            {
                container[i][j] -= value;
            }
        }
        return container;
    }

    //multiplication operators
    template <typename T>
    Matrix<T> Matrix<T>::operator * (const Matrix<T> & obj)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        Matrix<T> tmp(size_row,obj.get_number_of_columns());
        if (size_column != obj.get_number_of_rows())
        {
            std::cout<<"Impossible to do multiplication operator"<<std::endl;
            return tmp;
        }
        for (size_t i = 0;i < size_row;++i)
            for (size_t j = 0;j < obj.get_number_of_columns();++j)
                for (size_t k = 0;k < size_column;++k)
                    tmp.container[i][j] += container[i][k] * obj.container[k][j];
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator *= (const Matrix<T> & obj)
    {

        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        Matrix<T> tmp(size_row,obj.get_number_of_columns());
        if (size_column != obj.get_number_of_rows())
        {
            std::cout<<"Impossible to do multiplication operator"<<std::endl;
            return container;
        }
        for (size_t i = 0;i < size_row;++i)
            for (size_t j = 0;j < obj.get_number_of_columns();++j)
                for (size_t k = 0;k < size_column;++k)
                    tmp.container[i][j] += container[i][k] * obj.container[k][j];
        container = tmp.container;
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator * (const T & value)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        Matrix<T> tmp(size_row,size_column);
        for (size_t i = 0;i < size_row;++i)
            for (size_t j = 0;j < size_column;++j)
                tmp[i][j] = value * container[i][j];
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator *= (const T & value)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        for (size_t i = 0;i < size_row;++i)
            for (size_t j = 0;j < size_column;++j)
                container[i][j] *= value;
        return container;
    }

    //Division operators
    template <typename T>
    Matrix<T> Matrix<T>::operator / (const T & value)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        Matrix<T> tmp(size_row,size_column);
        for (size_t i = 0;i < size_row;++i)
            for (size_t j = 0;j < size_column;++j)
                tmp[i][j] = container[i][j] / value;
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator /= (const T & value)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        for (size_t i = 0; i< size_row;++i)
            for (size_t j = 0;j < size_column;++j)
                container[i][j] /= value;
        return container;
    }


    //assignment operator
    template <typename T>
    Matrix<T> Matrix<T>::operator = (const Matrix<T> & obj)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        if (size_row != obj.get_number_of_rows() || size_column != obj.get_number_of_columns ())
        {
            std::cout<<"not variable 2 matrix"<<std::endl;
            return container;
        }
        for (size_t i = 0;i < size_row;++i)
            for (size_t j = 0;j < size_column;++j)
            {
                container[i][j] = obj.container[i][j];
            }
        return container;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator = (const std::vector<T> & obj)
    {
        const size_t size_row = obj.size();
        Matrix<T> tmp(size_row,1);
        for (size_t i = 0;i < size_row;++i)
            container[0][i] = obj[i];
        return tmp;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator = (const vector & obj)
    {
        const size_t size = obj.size();
        if (obj.vec_val())
        {
            Matrix<T> tmp(size,1);
            for (size_t i = 0;i < size;++i)
                tmp[0][i] = obj[i];
            return tmp;
        }
            Matrix<T> tmp(1,size);
            const size_t size_column = obj.size();
            for (size_t i = 0;i < size_column;++i)
                tmp[i][0] = obj[i];
            return tmp;
    }

    template <typename T>
    bool Matrix<T>::operator == (const Matrix<T> & obj)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        if (size_row != obj.get_number_of_rows() || size_column != obj.get_number_of_columns ())
        {
            return false;
        }
        for (size_t i = 0;i < size_row;++i)
            for (size_t j = 0;j < size_column;++j)
                if (container[i][j] != obj.container[i][j])
                    return false;
        return true;
    }

    template <typename T>
    bool Matrix<T>::operator != (const Matrix<T> & obj)
    {
        const size_t size_row = get_number_of_rows();
        const size_t size_column = get_number_of_columns();
        if (size_row != obj.get_number_of_rows() || size_column != obj.get_number_of_columns ())
        {
            return true;
        }
        for (size_t i = 0;i < size_row;++i)
            for (size_t j = 0;j < size_column;++j)
                if (container[i][j] != obj.container[i][j])
                    return true;
        return false;
    }

    template <typename T>
    void Matrix<T>::print ()const
    {
        for (size_t i = 0;i < get_number_of_rows();++i)
        {
            std::cout<<std::endl;
            for (size_t j = 0;j < get_number_of_columns();++j)
                std::cout<<container[i][j]<<" , ";
            std::cout<<"\b";
        }
    }

    template <typename T>
    std::vector<T> & Matrix<T>::operator [] (const size_t & index)
    {
        return container[index];
    }

    template <typename T>
    const std::vector<T> & Matrix<T>::operator [] (const size_t & index)const
    {
        return get_row(index);
    }


    //Struck Vector
    template <typename T>
    Matrix<T>::vector:: vector (container_type & container_ ,size_t index_, bool bRow_):m_container(container_), m_index(index_), bRow(bRow_)
    {

    }

    template <typename T>
    Matrix<T>::vector::vector(const vector& other):m_container(other.m_container),m_index(other.m_index), bRow(other.bRow)
    {

    }

    template <typename T>
    T& Matrix<T>::vector::operator [](const size_t index)
    {
        if (bRow)
            return m_container[m_index][index];
        return m_container[index][m_index ];
    }

    template <typename T>
    size_t Matrix<T>::vector::size()
    {
        if (bRow)
            return m_container.front().size();
        return m_container.size();
    }

    template <typename T>
    bool Matrix<T>::vector::vec_val ()
    {
        return bRow;
    }
}//end name_space
#endif

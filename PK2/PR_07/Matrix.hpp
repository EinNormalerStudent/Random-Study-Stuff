/* 
 * File:   Matrix.hpp
 * Author: Danny
 *
 * Created on 23. Februar 2015, 14:16
 */

#ifndef Matrix_H
#define Matrix_H

template <class T> class Matrix{
    private:
        int m_Dimension;
        T ** m_CoreMatrix;
    public:
        
        //Operatoren
        
        Matrix(int dimension) : m_Dimension(dimension) {
            this->m_CoreMatrix = new T*[m_Dimension];
    
            for (int i = 0; i < m_Dimension; i++) {
                this->m_CoreMatrix[i] = new T[m_Dimension];
            }
    
        }

        int getDimension() const {
            return this->m_Dimension;
        }
        
        void set(int row, int col, T value){
            this->m_CoreMatrix[row][col] = value;
        }

        T  get(int row, int col) const {
            return this->m_CoreMatrix[row][col];
        }
        
        Matrix<T> operator* (Matrix<T> & m){
            int dim = m.getDimension();
            Matrix<T> m1(dim);
            for (int i = 0; i < dim; i++){
                for (int j = 0; j < dim; j++) {
                    for (int k = 0; k < dim; k++) {
                        m1.set(i,j, m1.get(i,j) + m.get(i,k) * this->m_CoreMatrix[k][j] );
                    }
                }
            }
            return m1;
        }

        template <typename Z>
        friend std::ostream& operator<<(std::ostream&, Matrix<Z> const&);
};

template <typename Z>
std::ostream& operator<<(std::ostream& tmpout, Matrix<Z> const& m){
    for (int i=0; i< m.getDimension(); i++) {
        for (int u = 0; u< m.getDimension(); u++) {
            tmpout << std::setw(3) << m.get(i, u);
        }
        tmpout<<std::endl;
    }
    
    return tmpout;
}

#endif	/* Matrix_H */

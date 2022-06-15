/*
 * Arquivo: cfifo.h
 * Autor: Arliones Hoeller
 * Organização: IFSC-SJE
 */

#ifndef __CFIFO_H__
#define __CFIFO_H__

template<int N, typename T>
class CircularFifo
{
public:


    CircularFifo() : in(0)
    {
       for (int i = 0; i < N; i++)
        data[i] = 0;

        in = N-1;
    }

    ~CircularFifo() {

    }

    void enqueue(T obj)
    {
       in = ((in == N-1) ? 0 : (in+1));
       data[in] = obj;
    }

    T dequeue(int i)
    {
        int ii = ((unsigned)(in - i)) % N;
        return data[ii];
    }

  
private:
    T data[N];
    int in;
};


#endif /* __CFIFO_H__ */
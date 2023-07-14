        #ifndef MOVEVECTOR_H
    #define MOVEVECTOR_H

    #include "basee.h"

    class MoveVector
    {
    public:
        MoveVector();
        void toZeroVector();
        void GenerateVector();
        void AddVx(qreal deltax);
        void AddVy(qreal deltay);
        QString StateofMoveKeys[4];//记录键盘相关键的状态
        qreal Vx;
        qreal Vy;
    };


    #endif // MOVEVECTOR_H

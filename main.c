#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max_students 30     //�궨�����ѧ���������޸ģ�//



//**********************************************//      //--------------------------------------//
//                                              //      //                                      //
//  Project_Name: GradeManagementSystem(GMS)    //      //      ��������������                  //
//                                              //      //              10-40 ע��              //
//  Developer_Name: Shen Chuhan                 //      //              42-77 �������          //
//                                              //      //              81-121 main��������     //
//  Developer_Number: 200320623                 //      //              122-272 ���ܷ�֧�ṹ    //
//                                              //      //              274-645 �Ӻ�������      //
//  Project_Version: V1.0                       //      //                                      //
//                                              //      //                                      //
//  Development Date: 2020/10/27                //      //                                      //
//                                              //      //                                      //
//**********************************************//      //--------------------------------------//




//**********************************************************************************//
//
//
//��ע����������ԭ��Ҫ���׼��������    1.��ID��������������ɼ���
//
//                                      2.Clear_record ��������������ѧ�����ݡ�
//
//                                      3.Calculate variance & standard deviation ���ڼ�������ķ���ͱ�׼�
//
//                                      4.������ӵ�С���Ȥ����UI���档
//
//                                      5.����ȫ����Ķ������ͳ������ơ�
//
//                                      6.����������ʾ��¼��ɼ������ӽ���Ƶ����ֵʱ�������û�����������ﵽ�������ʱ���������Է������±�Խ��
//
//
//                                      7.ϸ���Ż�����ʼ��ȫ�ֱ���students_numberΪ-1������0���������û���δ¼�����ݾ������·�����ʱ�����ĳ�0����
//
//**********************************************************************************//

//-----------/ ȫ�ֱ��������� /-------------------------//

long long int number[ max_students ] = {0};
long long int score[ max_students ] = {0};
long long int record_number[ max_students ] = {0};
long long int record_score[ max_students ] = {0};


int Exit = 0;
int students_number = -1;
long long int Num_search = 0;

//******************************************************//

//------------------------------------------------------/ �Ӻ��������� /-----------------------------------------------------------------//

int input_score( long long int number[] , long long int score[] , long long int record_number[] , long long int record_score[] );         //meau 1���ܺ���//

void sum_average( int n , long long int score[] );                                                                                           //meau 2���ܺ���//


void sorting_H_L( long long int number[] , long long int score[] );                                                                         //meau 3���ܺ���//
void sorting_L_H( long long int number[] , long long int score[] );                                                                         //meau 4���ܺ���//


void IDsort_H_L( long long int number[] , long long int score[] );                                                                          //meau 5���ܺ���//
void IDsort_L_H( long long int number[] , long long int score[] );                                                                          //meau 6���ܺ���//


void Score_search( long long int number[] , long long int score[] , long long int Num_search );                                            //meau 7���ܺ���//

void Statistic_analysis ( long long int number[] , long long int score[] );                                                                 //meau 8���ܺ���//

void List_record ( long long int record_number[] , long long int record_score[] );                                                          //meau 9���ܺ���//

void Clear_record ( long long int number[] , long long int score[] , long long int record_number[] , long long int record_score[] );      //meau 10���ܺ���//

void Calculate_variance_std_deviation ( long long int score[] );                                                                              //meau 11���ܺ���//

//****************************************************************************************************************************************//

int main()
{

    printf("Number: 200320623\nProject No.5 - Program No.1\n\n");

    int choice = 0;
    int S_N = 0;
    do
    {
        choice = 0;

        printf(" *----------------------------------------------------------------------------------------------------------------*\n");
        printf(" |                                                                                         _______________________|\n");
        printf(" |      _____                |***********************************************************| |                     ||\n");
        printf(" |     /     /      /   /    ||    GradeManagementSystem V1.0         G   M   S         || | /       /           ||\n");
        printf(" |    /            //  //    ||                                                         || |  /     /       ___  ||\n");
        printf(" |   /    ___     / / / /    ||                    // System Meau //                    || |   /   /   |   |   | ||\n");
        printf(" |   /       /   /  //  /    ||                                                         || |    / /    |   |   | ||\n");
        printf(" |    /      /  /   /   /    ||   1.  Input record                                      || |     /     | . |___| ||\n");
        printf(" |     /____/  /        /    ||   2.  Calculate total and average score of course       || |_____________________||\n");
        printf(" |                           ||   3.  Sort in descending order by score                 ||                        |\n");
        printf(" |        //////             ||   4.  Sort in ascending order by score                  ||        __              |\n");
        printf(" |       /      /            ||   5.  Sort in descending order by student's ID          ||      _|__|_       /|   |\n");
        printf(" |      /       /            ||   6.  Sort in ascending order by student's ID           ||     <( o_o)/     / |   |\n");
        printf(" |      /                    ||   7.  Search by student's ID                            ||                 /  |   |\n");
        printf(" |      /                    ||   8.  Statistic analysis                                ||                ( D D)  |\n");
        printf(" |       //////              ||   9.  List record                                       ||   666~~~       (_ o_)  |\n");
        printf(" |             /             ||   10. Clear record                                      ||                 / /    |\n");
        printf(" |              /            ||   11. Calculate variance & standard deviation           ||                        |\n");
        printf(" |     /       /             ||   12. Exit                                              ||             ( 'v')/    |\n");
        printf(" |      ///////              ||               Please enter your choice:                 ||                        |\n");
        printf(" |                           ||                                                         ||     ( `~`)             |\n");
        printf(" |                           |***********************************************************|                        |\n");
        printf(" |                                                                                                                |\n");
        printf(" *----------------------------------------------------------------------------------------------------------------*\n");




        scanf("%d", &choice );

        switch( choice )            //��meau��ѡ��ƽ�еĹ����б�//
        {
    case 1:

            students_number = input_score( number , score , record_number , record_score );                 //��������//

            printf("\n         |*******************************************************|\n");
            printf  ("             %d students_data got! Press Enter to return meau.    \n", students_number );
            printf  ("         |*******************************************************|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 2:

            S_N = students_number;                                                                          //��ƽ�������ܺ�//
            sum_average( S_N , score );

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 3:

            sorting_H_L( number , score );                                                                  //�����ɸ���������//

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 4:

            sorting_L_H( number , score );                                                                  //�����ɵ���������//

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 5:

            IDsort_H_L( number , score );                                                                   //��ID�ɸ��������У����ӹ��ܣ�//

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 6:

            IDsort_L_H( number , score );                                                                   //��ID�ɵ���������//

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 7:

            printf("\n         |-------------------------------------------------|\n");                     //��ID����ѧ���ɼ�//
            printf  ("         |*   Please input the number you want to search. *|\n");
            printf  ("         |-------------------------------------------------|\n");
            scanf("%lld",&Num_search);

            Score_search( number , score , Num_search);

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 8:

            Statistic_analysis( number , score );                                                           //���ȼ�����ͳ��//

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 9:

            List_record( record_number , record_score );                                                    //���������ݵ�record���//

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 10:

            Clear_record( number , score , record_number , record_score );                                  //����������record�����ӹ��ܣ�//

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 11:

            Calculate_variance_std_deviation( score );                                                      //��ѧ�������ķ������׼����ӹ��ܣ�//

            printf("\n         |----------------------------------|\n");
            printf  ("         |*   Press  Enter to return meau. *|\n");
            printf  ("         |----------------------------------|\n");

            while( getchar() != '\n' );
            getchar();
            break;

    case 12:

            Exit = 1;                                                                                       //�ı��ʶֵExit���˳�����//
            break;

        }
        }
        while( Exit == 0 );
}



//********************************// choice 1 //***************************************//

int input_score( long long int number[] , long long int score[] , long long int record_number[] , long long int record_score[] )
{
    long long int Num = 0;
    long long int Scr = 0;


    printf("    |********************************************|\n");
    printf("    |                                            |\n");
    printf("    | Input a negative number to stop enter data.|\n");
    printf("    |                                            |\n");
    printf("    |********************************************|\n");


    int n = 0;
    for(; n < max_students; n++)
    {
        printf("\nPlease input the number and the score of this student. (number/score)\n\n");
        scanf("%lld/%lld", &Num , &Scr );
        number[n] = Num;
        record_number[n] = Num;
        score[n] = Scr;
        record_score[n] = Scr;
        if(Num < 0 || Scr < 0) break;
        if( (n+1) >= 25 ) printf("\n  Be careful,there are already %d students! We can only get %d students.", (n+1) , max_students );
    }
    return (n);
}

//*************************************************************************************//

//********************************// choice 2 //***************************************//

void sum_average( int n , long long int score[] )
{
    int sum = 0;
    double average = 0;
    int N = 0;
    for(; N < n ; N++)
    {
        sum = sum + score[N];
    }
    average = ( (double)sum / (double)n );
    printf("\n\n            The sum of score is %d\n            The average score is %.3f", sum , average );
}

//*************************************************************************************//

//********************************// choice 3 //***************************************//

void sorting_H_L( long long int number[] , long long int score[] )
{
    int n3_1 = students_number -1 ;
    int n3_2 = 0;
    int n3_3 = 0;
    long long int swap1 = 0;
    long long int swap2 = 0;

    for( n3_1 = students_number -1 ; n3_1 > 0 ; n3_1-- )
    {
        n3_2 = 0;
        for(; n3_2 < n3_1 ; n3_2++ )
        {
            if( score[n3_2] < score[n3_2 + 1] )
            {
                swap1 = score[n3_2];
                score[n3_2] = score[n3_2 + 1];
                score[n3_2 + 1] = swap1;

                swap2 = number[n3_2];
                number[n3_2] = number[n3_2 + 1];
                number[n3_2 + 1] = swap2;
            }
        }
    }

    printf("\n");
    printf("\n\n         |**********************************|\n");
    printf("         |*   Sorting from high to low :   *|\n");
    printf("         |**********************************|\n");
    printf("-----------------------------------------------------------------\n");

    for(; n3_3 < students_number ; n3_3++ )
    {
        printf("   No.%d   Number = %lld    score = %lld\n", ( n3_3 +1 ) , number[n3_3] , score[n3_3] );
    }

    printf("-----------------------------------------------------------------\n");
}

//*************************************************************************************//

//********************************// choice 4 //***************************************//

void sorting_L_H( long long int number[] , long long int score[] )
{
    int n3_1 = students_number -1 ;
    int n3_2 = 0;
    int n3_3 = 0;
    long long int swap1 = 0;
    long long int swap2 = 0;

    for( n3_1 = students_number -1 ; n3_1 > 0 ; n3_1-- )
    {
        n3_2 = 0;
        for(; n3_2 < n3_1 ; n3_2++ )
        {
            if( score[n3_2] > score[n3_2 + 1] )
            {
                swap1 = score[n3_2];
                score[n3_2] = score[n3_2 + 1];
                score[n3_2 + 1] = swap1;

                swap2 = number[n3_2];
                number[n3_2] = number[n3_2 + 1];
                number[n3_2 + 1] = swap2;
            }
        }
    }

    printf("\n");
    printf("\n\n         |**********************************|\n");
    printf("         |*   Sorting from low to high :   *|\n");
    printf("         |**********************************|\n");
    printf("-----------------------------------------------------------------\n");

    for(; n3_3 < students_number ; n3_3++ )
    {
        printf("   No.%d   Number = %lld    score = %lld\n", ( n3_3 +1 ) , number[n3_3] , score[n3_3] );
    }

    printf("-----------------------------------------------------------------\n");
}

//*************************************************************************************//

//********************************// choice 5 //***************************************//

void IDsort_H_L( long long int number[] , long long int score[] )
{
    int n3_1 = students_number -1 ;
    int n3_2 = 0;
    int n3_3 = 0;
    long long int swap1 = 0;
    long long int swap2 = 0;

    for( n3_1 = students_number -1 ; n3_1 > 0 ; n3_1-- )
    {
        n3_2 = 0;
        for(; n3_2 < n3_1 ; n3_2++ )
        {
            if( number[n3_2] < number[n3_2 + 1] )
            {
                swap1 = score[n3_2];
                score[n3_2] = score[n3_2 + 1];
                score[n3_2 + 1] = swap1;

                swap2 = number[n3_2];
                number[n3_2] = number[n3_2 + 1];
                number[n3_2 + 1] = swap2;
            }
        }
    }

    printf("\n");
    printf("\n\n         |**********************************|\n");
    printf("         |*   Sorting from high to low :   *|\n");
    printf("         |**********************************|\n");
    printf("-----------------------------------------------------------------\n");

    for(; n3_3 < students_number ; n3_3++ )
    {
        printf("   No.%d   Number = %lld    score = %lld\n", ( n3_3 +1 ) , number[n3_3] , score[n3_3] );
    }

    printf("-----------------------------------------------------------------\n");
}

//*************************************************************************************//

//********************************// choice 6 //***************************************//

void IDsort_L_H( long long int number[] , long long int score[] )
{
    int n3_1 = students_number -1 ;
    int n3_2 = 0;
    int n3_3 = 0;
    long long int swap1 = 0;
    long long int swap2 = 0;

    for( n3_1 = students_number -1 ; n3_1 > 0 ; n3_1-- )
    {
        n3_2 = 0;
        for(; n3_2 < n3_1 ; n3_2++ )
        {
            if( number[n3_2] > number[n3_2 + 1] )
            {
                swap1 = score[n3_2];
                score[n3_2] = score[n3_2 + 1];
                score[n3_2 + 1] = swap1;

                swap2 = number[n3_2];
                number[n3_2] = number[n3_2 + 1];
                number[n3_2 + 1] = swap2;
            }
        }
    }

    printf("\n");
    printf("\n\n         |**********************************|\n");
    printf("         |*   Sorting from low to high :   *|\n");
    printf("         |**********************************|\n");
    printf("-----------------------------------------------------------------\n");

    for(; n3_3 < students_number ; n3_3++ )
    {
        printf("   No.%d   Number = %lld    score = %lld\n", ( n3_3 +1 ) , number[n3_3] , score[n3_3] );
    }

    printf("-----------------------------------------------------------------\n");
}

//*************************************************************************************//

//********************************// choice 7 //***************************************//

void Score_search( long long int number[] , long long int score[] , long long int Num_search )
{
    int n3_1 = students_number -1 ;
    int n3_2 = 0;
    int n3_3 = 0;
    long long int swap1 = 0;
    long long int swap2 = 0;

    for( n3_1 = students_number -1 ; n3_1 > 0 ; n3_1-- )
    {
        n3_2 = 0;
        for(; n3_2 < n3_1 ; n3_2++ )
        {
            if( score[n3_2] < score[n3_2 + 1] )
            {
                swap1 = score[n3_2];
                score[n3_2] = score[n3_2 + 1];
                score[n3_2 + 1] = swap1;

                swap2 = number[n3_2];
                number[n3_2] = number[n3_2 + 1];
                number[n3_2 + 1] = swap2;
            }
        }
    }

    int find_or_not = 0;
    for(; n3_3 < students_number ; n3_3++ )
    {
        if(Num_search == number[n3_3])
        {
            printf("-----------------------------------------------------------------\n");
            printf("\n  Ranking = %d    Number = %lld    score = %lld\n",(n3_3 + 1) , number[n3_3] , score[n3_3] );
            printf("-----------------------------------------------------------------\n");
            find_or_not = 1;
        }
    }
    if( find_or_not == 0 ) printf("\n\n     //* NOT FOUND *//\n\n");                                                      //���δ�ҵ���Ӧѧ��ѧ�ţ��򱨸�NOT FOUND//
}

//*************************************************************************************//

//********************************// choice 8 //***************************************//

void Statistic_analysis ( long long int number[] , long long int score[] )
{
    int n3_1 = 0;
    int A_level = 0;
    int B_level = 0;
    int C_level = 0;
    int D_level = 0;
    int E_level = 0;

    for(; n3_1 < students_number ; n3_1++ )
    {
        if( score[n3_1] > 100 || score[n3_1] < 0 ) printf("\n    The score of number: %lld  is wrong!\n", number[n3_1] );   //���������涨�޶ȵķ����ᱻ�������//
        if( score[n3_1] >= 90 && score[n3_1] <= 100 ) A_level++;
        if( score[n3_1] >= 80 && score[n3_1] <= 89 ) B_level++;
        if( score[n3_1] >= 70 && score[n3_1] <= 79 ) C_level++;
        if( score[n3_1] >= 60 && score[n3_1] <= 69 ) D_level++;
        if( score[n3_1] >= 0 && score[n3_1] <= 59 ) E_level++;
    }

    printf("-----------------------------------------------------------------\n");
    printf("\nThe A = %d  ( %.2f%% ) \n", A_level , ( (double)A_level ) / ( (double) students_number ) * 100 );
    printf("\nThe B = %d  ( %.2f%% ) \n", B_level , ( (double)B_level ) / ( (double) students_number ) * 100 );
    printf("\nThe C = %d  ( %.2f%% ) \n", C_level , ( (double)C_level ) / ( (double) students_number ) * 100 );
    printf("\nThe D = %d  ( %.2f%% ) \n", D_level , ( (double)D_level ) / ( (double) students_number ) * 100 );
    printf("\nThe E = %d  ( %.2f%% ) \n", E_level , ( (double)E_level ) / ( (double) students_number ) * 100 );
    printf("-----------------------------------------------------------------\n");
}

//*************************************************************************************//

//********************************// choice 9 //***************************************//

void List_record ( long long int record_number[] , long long int record_score[] )
{
    int n3_1 = 0;

    printf("\n");
    printf("\n\n         |**********************************|\n");
    printf("         |*      Record Data is below      *|\n");
    printf("         |**********************************|\n");
    printf("-----------------------------------------------------------------\n");

    for(; n3_1 < students_number ; n3_1++ )
    {
        printf("   No.%d   Number = %lld    score = %lld\n", ( n3_1 +1 ) , record_number[n3_1] , record_score[n3_1] );
    }

    printf("-----------------------------------------------------------------\n");
}

//*************************************************************************************//

//********************************// choice 10 //**************************************//

void Clear_record ( long long int number[] , long long int score[] , long long int record_number[] , long long int record_score[] )
{
    int n3_1 = 0;

    for(; n3_1 < max_students ; n3_1++ )
    {
        number[n3_1] = 0;
        record_number[n3_1] = 0;
        score[n3_1] = 0;
        record_score[n3_1] = 0;
    }

    printf("-----------------------------------------------------------------\n");
    printf("\n\a     Record Data Cleared ! \n\n");
    printf("-----------------------------------------------------------------\n");
}

//*************************************************************************************//

//********************************// choice 11 //**************************************//

void Calculate_variance_std_deviation ( long long int score[] )
{
    int n3_1 = 0;
    double variance = 0;
    double Dvariance = 0;

    int sum = 0;
    double average = 0;
    int N = 0;
    for(; N < students_number ; N++)
    {
        sum = sum + score[N];
    }
    average = ( (double)sum / (double)students_number );

    for(; n3_1 < students_number ; n3_1++ )
    {
        Dvariance = pow( ( score[n3_1] - average ) , 2 );
        variance = variance + Dvariance;
    }

    printf("-----------------------------------------------------------------\n");
    printf("\n   The variance of score is %lf  \n   The standard deviation is %lf\n", ( variance / students_number ) , sqrt( ( variance / students_number ) ) );
    printf("-----------------------------------------------------------------\n");
}

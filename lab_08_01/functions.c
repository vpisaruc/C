int GausMethod(int row, int column, double **matrix, FILE *file)
{
    if(row == column - 1)
    {
        if(row > 1 && column > 2)
        {    
            int n = row;
            int L = 0;
            double max_el = 0.0;
            
            double tmpf = 0.0, tmpf2 = 0.0, t3 = 0.0;
            for(int j = 0; j < n; j++)
            {
                for(int h = 0; h < n; h++)
                {
                    if(fabs(matrix[h][j]) > max_el)
                    {
                        max_el  = fabs(matrix[h][j]);
                    }
                }
                for(int k = 1 + L; k < n; k++)
                {
                    tmpf = matrix[k][j] / matrix[L][j];
                    for (int i = 0; i <= n; i++)
                    {
                        if (fabs(tmpf) == 0)
                        {
                            break;
                        }
                        tmpf2 = (matrix[L][i] * tmpf);
                        t3 = matrix[k][i] - tmpf2;
                        matrix[k][i] = t3;
                    }
                }
                L++;
            }
            
            double x[row];
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                double s = 0;
                for(int j = n - 1; j > i; j--)
                {
                    s += x[j] * matrix[i][j];
                }
                x[i] = (matrix[i][n] - s) / matrix[i][i];
                if (x[i] == 0)
                {
                    x[i] = fabs(x[i]);
                }
                cnt++;
            }

            fprintf(file,"%d ", 1);
            fprintf(file, "%d\n", cnt);
            for(int i = 0; i < row; i++)
            {
                fprintf(file,"%lf\n", x[i]);
            }
            return OK;
        }
    }
    else
    {
        return GAUS_ERROR;
    }
}
def rotate(matrix):
    n,m = len(matrix),len(matrix[0])
    for i in range(n):
        for j in range(i+1,m):
            matrix[i][j],matrix[j][i]= matrix[j][i],matrix[i][j]
    for i in range(n//2):
        for j in range(m):
            matrix[i][j],matrix[n-i-1][j]=matrix[n-i-1][j],matrix[i][j]

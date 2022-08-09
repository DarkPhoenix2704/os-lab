#!/bin/bash
echo "Enter the Limit" 
read n 
for((i=1;i<=n;i++)) 
do 
for((j=1;j<=i;j++)) 
do 
echo -n " $j " 
done 
echo 
done
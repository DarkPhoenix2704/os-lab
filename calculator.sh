result=0
i="y" 
echo "Enter the First Number:" 
read n1 
echo "Enter the Second Number:" 
read n2 
while [ $i = "y" ] 
do 
echo "1.Addition " 
echo "2.Substraction " 
echo "3.Multiplication " 
echo "4.Division " 
echo "Enter your choice " 
read ch 
case $ch in 
1) result=`expr $n1 + $n2` 
echo "Sum is $result" 
;; 
2) result=`expr $n1 - $n2` 
echo "Difference is $result" 
;; 
3) result=`expr $n1 * $n2` 
echo "Product is $result" 
;; 
4) result=`expr $n1 / $n2` 
echo "Division is $result" 
;; 
*)echo "Invalid choice" 
;; 
esac 
echo "Do you want to continue" 
read i 
if [ $i!="y" ] 
then 
exit 
fi 
done
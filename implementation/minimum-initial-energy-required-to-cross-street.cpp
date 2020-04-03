/*Minimum Initial Energy Required To Cross Street
Given an array containing positive and negative numbers. The array represents checkpoints from one end to other end of street. 
Positive and negative values represent amount of energy at that checkpoint. Positive numbers increase the energy and negative numbers decrease. 
Find the minimum initial energy required to cross the street such that Energy level never becomes 0 or less than 0.

Note : The value of minimum initial energy required will be 1 even if we cross street successfully without 
loosing energy to less than and equal to 0 at any checkpoint. The 1 is required for initial check point.*/
// Function to calculate minimum initial energy
// arr[] stores energy at each checkpoints on street
int minInitialEnergy(int arr[], int n)
{
    // initMinEnergy is variable to store minimum initial
    // energy required.
    int initMinEnergy = 0;
 
    // currEnergy is variable to store current value of
    // energy at i'th checkpoint on street
    int currEnergy = 0;
 
    // flag to check if we have successfully crossed the
    // street without any energy loss <= o at any checkpoint
    bool flag = 0;
 
    // Traverse each check point lineraly
    for (int i=0; i<n; i++)
    {
        currEnergy += arr[i];
 
        // If current energy, becomes negative or 0, increment
        // initial minimum energy by the negative value plus 1.
        // to keep current energy positive (at least 1). Also
        // update current energy and flag.
        if (currEnergy <= 0)
        {
            initMinEnergy += abs(currEnergy) +1;
            currEnergy = 1;
            flag = 1;
        }
    }
 
    // If energy never became negative or 0, then
    // return 1. Else return computed initMinEnergy
    return (flag == 0)? 1 : initMinEnergy;
}
// sketch_07_05_dynamic

int *array;

void setup()
{
  array = (int *)malloc(sizeof(int) * 100);
  array[0] = 1;
  array[50] = 2;
  Serial.begin(9600);
  Serial.println(array[50]);
}

void loop()
{
}

// 2664 bytes

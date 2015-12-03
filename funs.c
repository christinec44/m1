double pi_bbp (int n);
double pi_leibniz (int n);

double pi_bbp (int n) //function for bbp algorithm
{
    double a = 1.;
    double p = 0.;

    for (int k = 0; k < n; k++)
    {
        int k8 = 8 * k;
        double b = 4. / (k8 + 1);
        double c = 2. / (k8 + 4);
        double d = 1. / (k8 + 5);
        double e = 1. / (k8 + 6);

        p += a * (b - c - d - e);
        a /= 16.;
    }
    return p;
}

double pi_leibniz (int n)	//function for leibniz algorithm
{
    double p = 0.0, o;

    for (int i = 0; i < n; ++i)
    {
        o = 1.0 / (2 * i + 1);
        o = (i % 2 == 1) ? -o : o;      //Odd terms are subtracted, even terms are added
        p += o;
    }
    return 4 * p;
}


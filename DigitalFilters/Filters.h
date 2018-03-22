#pragma once

using namespace System::Drawing;

public ref class Filters
{
public:

	static double Filters::Get_G(double x, double K);
	static Bitmap ^ DummyFilter(Bitmap^ sourceImage);
	static double generateGaussianNoise(double mu, double sigma);
	static Bitmap^ GaussianNoise(Bitmap^ sourceImage, double mu, double sigma);
	static Bitmap^ Average(Bitmap^ sourceImage, int kernelSize);
	static Bitmap^ Filters::SaltPepper(Bitmap^ sourceImage, float prob);
	static Bitmap^ Filters::Sobel(Bitmap^ sourceImage);
	static Bitmap^ Filters::Prewitt(Bitmap^ sourceImage);
	static Bitmap^ AdaptiveThresholing(Bitmap^ sourceImage, int kernel);
	static Bitmap^ AnisotropicDifussion(Bitmap^ sourceImage, int iterations, double K, double lambda);
};


#include "stdafx.h"
#include "Filters.h"
#include <math.h>
#include <stdlib.h>
#include <limits>
#include <algorithm>
#include "vector"
#include "cmath"

using namespace std;
using namespace System::Drawing::Imaging;
using namespace System;



Bitmap^ Filters::DummyFilter(Bitmap^ sourceImage)
{
	return sourceImage;
}

double Filters::generateGaussianNoise(double mu, double sigma)
{
	const double epsilon = std::numeric_limits<double>::min();
	const double two_pi = 2.0*3.14159265358979323846;

	static double z0, z1;
	static bool generate;
	generate = !generate;

	if (!generate)
		return z1 * sigma + mu;

	double u1, u2;
	do
	{
		u1 = rand() * (1.0 / RAND_MAX);
		u2 = rand() * (1.0 / RAND_MAX);
	} while (u1 <= epsilon);

	z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
	z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
	return z0 * sigma + mu;
}

double g(double x)
{
	double y;
	int k = 1;
	y = 1 / (1 + (pow((abs(x) / k), 2.0)));
	return y;
}



double Filters::Get_G(double x, double K)
{
	double _x = x / K;
	double _x2 = _x*_x;
	return  1.0 / (1.0 + _x2);
}

Bitmap^ Filters::AnisotropicDifussion(Bitmap^ sourceImage, int iterations, double K, double lambda)
{
	int width = sourceImage->Width;
	int height = sourceImage->Height;
	Bitmap^ newImage = gcnew Bitmap(sourceImage);
	Bitmap^ tempImage = gcnew Bitmap(sourceImage);

	for (int i = 0; i < iterations; i++)
	{
		for (int h = 1; h < height - 1; h++)
		{
			for (int w = 1; w < width - 1; w++)
			{
				Color P = tempImage->GetPixel(w, h);
				Color E = tempImage->GetPixel(w + 1, h);
				Color W = tempImage->GetPixel(w - 1, h);
				Color S = tempImage->GetPixel(w, h - 1);
				Color N = tempImage->GetPixel(w, h + 1);

				int DW_R = W.R - P.R;
				int DW_G = W.G - P.G;
				int DW_B = W.B - P.B;

				int DE_R = E.R - P.R;
				int DE_G = E.G - P.G;
				int DE_B = E.B - P.B;

				int DN_R = N.R - P.R;
				int DN_G = N.G - P.G;
				int DN_B = N.B - P.B;

				int DS_R = S.R - P.R;
				int DS_G = S.G - P.G;
				int DS_B = S.B - P.B;

				// =================================

				double CW_R = Get_G(DW_R, K);
				double CW_G = Get_G(DW_G, K);
				double CW_B = Get_G(DW_B, K);

				double CE_R = Get_G(DE_R, K);
				double CE_G = Get_G(DE_G, K);
				double CE_B = Get_G(DE_B, K);

				double CN_R = Get_G(DN_R, K);
				double CN_G = Get_G(DN_G, K);
				double CN_B = Get_G(DN_B, K);

				double CS_R = Get_G(DS_R, K);
				double CS_G = Get_G(DS_G, K);
				double CS_B = Get_G(DS_B, K);

				double _R = lambda * (CW_R * DW_R + CE_R * DE_R + CN_R * DN_R + CS_R * DS_R);
				double _G = lambda * (CW_G * DW_G + CE_G * DE_G + CN_G * DN_G + CS_G * DS_G);
				double _B = lambda * (CW_B * DW_B + CE_B * DE_B + CN_B * DN_B + CS_B * DS_B);

				int r = Convert::ToInt32(_R + P.R);
				int g = Convert::ToInt32(_G + P.G);
				int b = Convert::ToInt32(_B + P.B);

				r = max(r, 0);
				r = min(r, 255);
				b = max(b, 0);
				b = min(b, 255);
				g = max(g, 0);
				g = min(g, 255);
				Color pp = Color::FromArgb(r, g, b);
				newImage->SetPixel(w, h, pp);

			}
		}

		tempImage = gcnew Bitmap(newImage);
	}
	return newImage;
}


Bitmap^ Filters::GaussianNoise(Bitmap^ sourceImage, double mu, double sigma)
{
	int width = sourceImage->Width;
	int height = sourceImage->Height;

	Bitmap^ newImage = gcnew Bitmap(width, height);

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			Color p = sourceImage->GetPixel(w, h);
			double noise = generateGaussianNoise(mu, sigma);
			int r = Convert::ToInt32(p.R + noise);
			int b = Convert::ToInt32(p.B + noise);
			int g = Convert::ToInt32(p.G + noise);
			r = max(r, 0);
			r = min(r, 255);
			b = max(b, 0);
			b = min(b, 255);
			g = max(g, 0);
			g = min(g, 255);
			Color pp = Color::FromArgb(r, g, b);
			newImage->SetPixel(w, h, pp);
		}
	}
	return newImage;
}


Bitmap^ Filters::Average(Bitmap^ sourceImage, int kernel)
{
	int width = sourceImage->Width;
	int height = sourceImage->Height;

	Bitmap^ newImage = gcnew Bitmap(sourceImage);

	int div = kernel * kernel;

	for (int h = 0; h < height; h++)
	{
		int hstart = max(h - kernel, 0);
		int hend = min(h + kernel, height);

		for (int w = 0; w < width; w++)
		{
			int wstart = max(w - kernel, 0);
			int wend = min(w + kernel, width);

			int N = 0;
			int r = 0;
			int g = 0;
			int b = 0;

			for (int hk = hstart; hk < hend; hk++)
			{
				for (int wk = wstart; wk < wend; wk++)
				{
					N++;
					Color c = newImage->GetPixel(wk, hk);
					r += c.R;
					g += c.G;
					b += c.B;
				}
			}
			r = r / N;
			g = g / N;
			b = b / N;
			Color pp = Color::FromArgb(r, g, b);
			newImage->SetPixel(w, h, pp);
		}
	}
	return newImage;
}


Bitmap^ Filters::AdaptiveThresholing(Bitmap^ sourceImage, int kernel)
{
	int width = sourceImage->Width;
	int height = sourceImage->Height;

	Bitmap^ newImage = gcnew Bitmap(sourceImage);

	int div = kernel * kernel;

	for (int h = 0; h < height; h++)
	{
		int hstart = max(h - kernel, 0);
		int hend = min(h + kernel, height);

		for (int w = 0; w < width; w++)
		{
			int wstart = max(w - kernel, 0);
			int wend = min(w + kernel, width);

			int N = 0;
			int r = 0;
			int g = 0;
			int b = 0;

			for (int hk = hstart; hk < hend; hk++)
			{
				for (int wk = wstart; wk < wend; wk++)
				{
					N++;
					Color c = sourceImage->GetPixel(wk, hk);
					r += c.R;
					g += c.G;
					b += c.B;
				}
			}

			int ave = (r + g + b) / (3 * N);

			Color cur = sourceImage->GetPixel(w, h);

			int val = (cur.R + cur.G + cur.B) / 3;

			if (val > ave)
			{
				newImage->SetPixel(w, h, Color::White);
			}
			else
			{
				newImage->SetPixel(w, h, Color::Black);
			}

		}
	}
	return newImage;
}



Bitmap^ Filters::SaltPepper(Bitmap^ sourceImage, float prob)
{
	int width = sourceImage->Width;
	int height = sourceImage->Height;

	Bitmap^ newImage = gcnew Bitmap(sourceImage);



	for (int h = 0; h < height; h++)
	{


		for (int w = 0; w < width; w++)
		{

			float ra = ((float)rand()) / RAND_MAX;
			if (ra < prob)
			{
				int i = rand() % 2;

				if (i == 0)
				{
					Color pp = Color::FromArgb(0, 0, 0);
					newImage->SetPixel(w, h, pp);
				}
				else
				{
					Color pp = Color::FromArgb(255, 255, 255);
					newImage->SetPixel(w, h, pp);
				}
			}
		}

	}
	return newImage;
}

Bitmap^ Filters::Sobel(Bitmap^ sourceImage)
{
	int kernel = 3;
	int width = sourceImage->Width;
	int height = sourceImage->Height;

	const int _SOBEL_Gx[3][3] = { { -1, 0, 1 }, { -2, 0, 2 }, { -1, 0, 1 } };
	// sobel map for the y axis
	const int _SOBEL_Gy[3][3] = { { 1, 2, 1 }, { 0, 0, 0 }, { -1, -2, -1 } };



	Bitmap^ newImage = gcnew Bitmap(sourceImage);

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{

			int sobel_gradient_xr = 0;
			int	sobel_gradient_yr = 0;

			int sobel_gradient_xb = 0;
			int	sobel_gradient_yb = 0;

			int sobel_gradient_xg = 0;
			int	sobel_gradient_yg = 0;

			int r = 0;
			int g = 0;
			int b = 0;
			int sy = 0;

			for (int my = h; my < h + 3; my++)
			{
				int sx = 0;
				for (int mx = w; mx < w + 3; mx++)
				{
					if (my < height && mx < width)
					{
						Color c = newImage->GetPixel(mx, my);
						r = c.R;
						g = c.G;
						b = c.B;

						sobel_gradient_xr += r * _SOBEL_Gx[sy][sx];
						sobel_gradient_yr += r * _SOBEL_Gy[sy][sx];

						sobel_gradient_xb += b * _SOBEL_Gx[sy][sx];
						sobel_gradient_yb += b * _SOBEL_Gy[sy][sx];

						sobel_gradient_xg += g * _SOBEL_Gx[sy][sx];
						sobel_gradient_yg += g * _SOBEL_Gy[sy][sx];
					}
					sx++;
				}
				sy++;
			}

			int sumr = abs(sobel_gradient_xr) + abs(sobel_gradient_yr);
			int sumg = abs(sobel_gradient_xg) + abs(sobel_gradient_yg);
			int sumb = abs(sobel_gradient_xb) + abs(sobel_gradient_yb);

			sumr = max(sumr, 0);
			sumr = min(sumr, 255);
			sumb = max(sumb, 0);
			sumb = min(sumb, 255);
			sumg = max(sumg, 0);
			sumg = min(sumg, 255);


			Color pp = Color::FromArgb(sumr, sumg, sumb);
			newImage->SetPixel(w, h, pp);

		}
	}
	return newImage;

}

Bitmap^ Filters::Prewitt(Bitmap^ sourceImage)
{
	int kernel = 3;
	int width = sourceImage->Width;
	int height = sourceImage->Height;

	const int _SOBEL_Gx[3][3] = { { -1, 0, 1 }, { -1, 0, 1 }, { -1, 0, 1 } };
	// sobel map for the y axis
	const int _SOBEL_Gy[3][3] = { { 1, 1, 1 }, { 0, 0, 0 }, { -1, -1, -1 } };



	Bitmap^ newImage = gcnew Bitmap(sourceImage);

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{

			int sobel_gradient_xr = 0;
			int	sobel_gradient_yr = 0;

			int sobel_gradient_xb = 0;
			int	sobel_gradient_yb = 0;

			int sobel_gradient_xg = 0;
			int	sobel_gradient_yg = 0;

			int r = 0;
			int g = 0;
			int b = 0;
			int sy = 0;

			for (int my = h; my < h + 3; my++)
			{
				int sx = 0;
				for (int mx = w; mx < w + 3; mx++)
				{
					if (my < height && mx < width)
					{
						Color c = newImage->GetPixel(mx, my);
						r = c.R;
						g = c.G;
						b = c.B;

						/*	r = max(r, 0);
						r = min(r, 255);
						b = max(b, 0);
						b = min(b, 255);
						g = max(g, 0);
						g = min(g, 255);*/

						sobel_gradient_xr += r * _SOBEL_Gx[sy][sx];
						sobel_gradient_yr += r * _SOBEL_Gy[sy][sx];

						sobel_gradient_xb += b * _SOBEL_Gx[sy][sx];
						sobel_gradient_yb += b * _SOBEL_Gy[sy][sx];

						sobel_gradient_xg += g * _SOBEL_Gx[sy][sx];
						sobel_gradient_yg += g * _SOBEL_Gy[sy][sx];
					}
					sx++;
				}
				sy++;
			}

			int sumr = abs(sobel_gradient_xr) + abs(sobel_gradient_yr);
			int sumg = abs(sobel_gradient_xg) + abs(sobel_gradient_yg);
			int sumb = abs(sobel_gradient_xb) + abs(sobel_gradient_yb);

			sumr = max(sumr, 0);
			sumr = min(sumr, 255);
			sumb = max(sumb, 0);
			sumb = min(sumb, 255);
			sumg = max(sumg, 0);
			sumg = min(sumg, 255);


			Color pp = Color::FromArgb(sumr, sumg, sumb);
			newImage->SetPixel(w, h, pp);

		}
	}
	return newImage;

}
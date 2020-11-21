#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> v(10);
	TMatrix<int> v1(v);
	EXPECT_EQ(v1, v);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{

	TMatrix<int> v(10);

	if (true) {
		TMatrix<int> v1(10);
		v = v1;
	}

	ASSERT_NO_THROW(v[0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(10);
	v[0][0] = 5;
	int x = v[0][0];

}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(10);
	TVector<int> v1(10);
	ASSERT_ANY_THROW(m[-1] = v1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(10);
	TVector<int> v1(10);
	ASSERT_ANY_THROW(m[MAX_MATRIX_SIZE] = v1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v;
	ASSERT_NO_THROW(v = v);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v(10);
	TMatrix<int> v1(10);
	ASSERT_NO_THROW(v = v1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> a(5);
	TMatrix<int> b(7);
	a = b;
	EXPECT_EQ(7, a.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> a(5);
	TMatrix<int> b(7);
	ASSERT_NO_THROW(a = b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	
	TVector<int> v(10);
	v = v + 5;

	TMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = v;
	}
	TMatrix<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = v;
	}
	EXPECT_EQ(true, a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> a(5);
	TVector<int> v(10);
	v = v + 5;

	for (int i = 0; i < 5; i++) {
		a[i] = v;
	}
	EXPECT_EQ(true, a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TVector<int> v(10);
	v = v + 5;
	
	TMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = v;
	}
	TMatrix<int> b(7);
	for (int i = 0; i < 5; i++) {
		b[i] = v;
	}
	EXPECT_NE(true, a == b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(10);

	TVector<int> v(10);

	for (int i = 0; i < 10; i++) {
		m1[i] = v + 1;
		m2[i] = v + 2;
	}

	TMatrix<int> m3(10);
	for (int i = 0; i < 10; i++) {
		m3[i] = v + 3;
	}

	EXPECT_EQ(m3, m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(5);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(10);

	TVector<int> v(10);

	for (int i = 0; i < 10; i++) {
		m1[i] = v + 1;
		m2[i] = v + 2;
	}

	TMatrix<int> m3(10);
	for (int i = 0; i < 10; i++) {
		m3[i] = v - 1;
	}

	EXPECT_EQ(m3, m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(10);
	TMatrix<int> m2(5);

	ASSERT_ANY_THROW(m1 - m2);
}


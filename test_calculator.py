import pytest
import calculator

def test_add_positive():
    assert calculator.add(2, 2) == 4

def test_add_zero():
    assert calculator.add(0, 0) == 0

def test_add_negative():
    assert calculator.add(-2, -2) == -4

class Parent(object):
	def __init__(self):
		print("Parent init")
		self.value = 5

	def get_value(self):
		print("Parent get value")
		return self.value

	def something(self):
		print("Test")
		return self.get_value()

class Child(Parent):
	def get_value(self):
		print("Child get value")
		return super().get_value()

c = Child()
c.something()

# Will output:
# ----------------
# Parent init
# Test
# Child get value
# Parent get value

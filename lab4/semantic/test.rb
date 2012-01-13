class A
	def initialize
		@a = 3
	end
	def mul(x)
		@a = x
	end
end
class B
	def initialize
		pi = 3.14
	end
end
class C < A
	def initialize
		@c = 1
		@d = 3
	end
	def mul(x)
		if x == 3 
			@c = @c * @d
		end
		super(@d)
	end
end

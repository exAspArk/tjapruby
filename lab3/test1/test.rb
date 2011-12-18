class A < B
	def meth
		a = "Stroka"
	end
end

class B 
	private : b
	def initialize(param)
		b = param
	end
	public def minus
		b += 1
		return b
	end
end

class C
	def initialize
		c = A.new
		c.minus
	end
end

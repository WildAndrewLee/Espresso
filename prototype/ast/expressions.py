# Note: This is the naive approach. I'll write a more proper
# implementation later so it handles parenthesis.

import re

grammars = {
	'ASSIGNMENT': [
		'EXPRESSION = ASSIGNMENT',
		'EXPRESSION <= ASSIGNMENT',
		'EXPRESSION >= ASSIGNMENT',
		'EXPRESSION != ASSIGNMENT'
	],

	'EXPRESSION': [
		'EXPRESSION + EXPRESSION',
		'EXPRESSION - EXPRESSION',
		'EXPRESSION * EXPRESSION',
		'EXPRESSION / EXPRESSION',
		'EXPRESSION++',
		'EXPRESSION--',
		'(EXPRESSION)',
	],

	'TERM': [
		str(x) for x in range(1, 10)
	]
}

levels = [
	'ASSIGNMENT',
	'EXPRESSION',
	'TERM'
]

tests = [
	'5 * (5 - 5) / 5'
]

class Node:
	def __init__(self):
		self.token = ''
		self.children = []

def parse(token, level = levels[0]):
	node = Node()

	rl = [x for x in levels if levels.index(x) >= levels.index(level)]

	for level in rl:
		for grammar in grammars[level]:
			grammar = re.sub(r'\s', '', grammar)
			regex = re.escape(grammar)
			regex = re.sub('|'.join(levels), '(.+)', regex)
			regex = '^' + regex + '$'

			print regex

			test = re.match(regex, token)
			rlevels = re.match(regex, grammar)

			if test:
				node.token = re.sub(r'\^|\(\.\+\)|\\|\$', '', regex)

				for t, g in zip(test.groups(), rlevels.groups()):
					node.children.append(parse(t, g))

				break

	return node

def printTree(node, depth = 0):
	print '\t' * depth, node.token

	for child in node.children:
		printTree(child, depth + 1)

for test in tests:
	print test
	printTree(parse(test))
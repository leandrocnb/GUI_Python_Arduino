

def send_to_arduino(self):
	"""junta todos os paramentros separando por ";""""
	body_info = self.potVertSuperior+";"+self.potVertInferior+";"+self.taxaVarredura+";"+self.numCliclos
	"""...colocar código para enviar usando a conexao 'body_info' para o arduido via comunicação serial..."""

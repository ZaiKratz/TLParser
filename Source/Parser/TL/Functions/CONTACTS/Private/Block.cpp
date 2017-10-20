#include "../Public/Block.h"


//begin namespace block
namespace CONTACTS
{

Block::Block()
{
	this->_ConstructorID = 858475004;
	this->_ContentRelated = true;
}

Block::Block(COMMON::InputUser*  id)
{
	this->_ConstructorID = 858475004;
	this->_ContentRelated = true;
	this->id = id;
}
void Block::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void Block::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
Block::~Block()
{
	if(this->id)
	{
		delete this->id;
	}
}
}//end namespace block

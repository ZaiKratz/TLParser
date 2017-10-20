#include "../Public/GetAllDrafts.h"


//begin namespace block
namespace MESSAGES
{

GetAllDrafts::GetAllDrafts()
{
	this->_ConstructorID = 1782549861;
	this->_ContentRelated = true;
}
void GetAllDrafts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetAllDrafts::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetAllDrafts::~GetAllDrafts()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block

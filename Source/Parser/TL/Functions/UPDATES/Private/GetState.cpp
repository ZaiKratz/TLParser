#include "../Public/GetState.h"


//begin namespace block
namespace UPDATES
{

GetState::GetState()
{
	this->_ConstructorID = -304838614;
	this->_ContentRelated = true;
}
void GetState::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetState::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<UPDATES::State*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetState::~GetState()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block

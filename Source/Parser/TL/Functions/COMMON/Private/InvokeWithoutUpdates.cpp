#include "../Public/InvokeWithoutUpdates.h"


//begin namespace block
namespace COMMON
{

InvokeWithoutUpdates::InvokeWithoutUpdates()
{
	this->_ConstructorID = -1080796745;
	this->_ContentRelated = true;
}

InvokeWithoutUpdates::InvokeWithoutUpdates(TLBaseObject*  query)
{
	this->_ConstructorID = -1080796745;
	this->_ContentRelated = true;
	this->query = query;
}
void InvokeWithoutUpdates::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->query->OnSend(Writer);
}


void InvokeWithoutUpdates::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	this->_Responded = true;
}
InvokeWithoutUpdates::~InvokeWithoutUpdates()
{

}
}//end namespace block

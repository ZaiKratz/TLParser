#include "../Public/DestroySession.h"


//begin namespace block
namespace COMMON
{

DestroySession::DestroySession()
{
	this->_ConstructorID = -414113498;
	this->_ContentRelated = true;
}

DestroySession::DestroySession(unsigned long long session_id)
{
	this->_ConstructorID = -414113498;
	this->_ContentRelated = true;
	this->session_id = session_id;
}
void DestroySession::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->session_id);
}


void DestroySession::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	this->_Responded = true;
}
DestroySession::~DestroySession()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block

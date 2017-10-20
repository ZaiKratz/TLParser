#include "../Public/ResolveUsername.h"


//begin namespace block
namespace CONTACTS
{

ResolveUsername::ResolveUsername()
{
	this->_ConstructorID = -113456221;
	this->_ContentRelated = true;
}

ResolveUsername::ResolveUsername(FString username)
{
	this->_ConstructorID = -113456221;
	this->_ContentRelated = true;
	this->username = username;
}
void ResolveUsername::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->username);
}


void ResolveUsername::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CONTACTS::ResolvedPeer*>(Reader.TGReadObject());
	this->_Responded = true;
}
ResolveUsername::~ResolveUsername()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block

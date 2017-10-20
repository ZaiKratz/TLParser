#include "../Public/ImportBotAuthorization.h"


//begin namespace block
namespace AUTH
{

ImportBotAuthorization::ImportBotAuthorization()
{
	this->_ConstructorID = 1738800940;
	this->_ContentRelated = true;
}

ImportBotAuthorization::ImportBotAuthorization(int32 flags, int32 api_id, FString api_hash, FString bot_auth_token)
{
	this->_ConstructorID = 1738800940;
	this->_ContentRelated = true;
	this->flags = flags;
	this->api_id = api_id;
	this->api_hash = api_hash;
	this->bot_auth_token = bot_auth_token;
}
void ImportBotAuthorization::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->flags);
	Writer.WriteInt(this->api_id);
	Writer.TGWriteString(this->api_hash);
	Writer.TGWriteString(this->bot_auth_token);
}


void ImportBotAuthorization::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::Authorization*>(Reader.TGReadObject());
	this->_Responded = true;
}
ImportBotAuthorization::~ImportBotAuthorization()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block

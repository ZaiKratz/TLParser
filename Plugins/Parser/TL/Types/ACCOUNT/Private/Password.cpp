#include "../Public/Password.h"


//begin namespace block
namespace ACCOUNT
{

Password::Password()
{
	this->_ConstructorID = 471079036;
}

Password::Password(TArray<uint8> current_salt, TArray<uint8> new_salt, FString hint, bool has_recovery, FString email_unconfirmed_pattern)
{
	this->_ConstructorID = 471079036;
	this->current_salt = current_salt;
	this->new_salt = new_salt;
	this->hint = hint;
	this->has_recovery = has_recovery;
	this->email_unconfirmed_pattern = email_unconfirmed_pattern;
}
void Password::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->current_salt.GetData(), this->current_salt.Num());
	Writer.TGWriteBytes((unsigned char*)this->new_salt.GetData(), this->new_salt.Num());
	Writer.TGWriteString(this->hint);
	Writer.WriteBool(this->has_recovery);
	Writer.TGWriteString(this->email_unconfirmed_pattern);
}


void Password::OnResponce(BinaryReader& Reader)
{
	current_salt = Reader.TGReadBytes();
	new_salt = Reader.TGReadBytes();
	hint = Reader.TGReadString();
	has_recovery = Reader.ReadBool();
	email_unconfirmed_pattern = Reader.TGReadString();
}
Password::~Password()
{

}
}//end namespace block

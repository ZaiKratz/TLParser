#include "../Public/HighScores.h"


//begin namespace block
namespace MESSAGES
{

HighScores::HighScores()
{
	this->_ConstructorID = -1711457382;
}

HighScores::HighScores(TArray<COMMON::HighScore*> scores, TArray<COMMON::User*> users)
{
	this->_ConstructorID = -1711457382;
	this->scores = scores;
	this->users = users;
}
void HighScores::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->scores.Num());
	for(auto X : this->scores)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void HighScores::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len6010 = Reader.ReadInt();
	for(int32 i = 0; i < Len6010; i++)
	{
	auto X = reinterpret_cast<COMMON::HighScore*>(Reader.TGReadObject());
	scores.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len8578 = Reader.ReadInt();
	for(int32 i = 0; i < Len8578; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
HighScores::~HighScores()
{

}
}//end namespace block

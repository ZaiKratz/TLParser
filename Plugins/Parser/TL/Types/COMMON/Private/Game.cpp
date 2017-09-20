#include "../Public/Game.h"


//begin namespace block
namespace COMMON
{

Game::Game()
{
	this->_ConstructorID = 996538813;
}

Game::Game(unsigned long long id, unsigned long long access_hash, FString short_name, FString title, FString description, COMMON::Photo* photo, COMMON::Document* document)
{
	this->_ConstructorID = 996538813;
	this->id = id;
	this->access_hash = access_hash;
	this->short_name = short_name;
	this->title = title;
	this->description = description;
	this->photo = photo;
	this->document = document;
}
void Game::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!document)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteString(this->short_name);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->description);
	this->photo->OnSend(Writer);
	if(!this->document)
	{
	this->document->OnSend(Writer);
	}
}


void Game::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	short_name = Reader.TGReadString();
	title = Reader.TGReadString();
	description = Reader.TGReadString();
	photo = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	if((Flags & (1 << 0)) != 0) 
	{
	document = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	}
}
Game::~Game()
{

}
}//end namespace block

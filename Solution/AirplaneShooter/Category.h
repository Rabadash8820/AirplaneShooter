namespace Shooter {

	enum Category {
		None		   = 0,
		Node		   = 1 << 0,
		PlayerAircraft = 1 << 1,
		AlliedAircraft = 1 << 2,
		EnemyAircraft  = 1 << 3,
	};
	
}
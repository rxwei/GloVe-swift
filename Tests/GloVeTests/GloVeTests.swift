import XCTest
@testable import GloVe

class GloVeTests: XCTestCase {
    func testExample() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
        XCTAssertEqual(GloVe().text, "Hello, World!")
    }


    static var allTests : [(String, (GloVeTests) -> () throws -> Void)] {
        return [
            ("testExample", testExample),
        ]
    }
}

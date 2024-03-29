#include "httplib.h"

int main() {
    // HTTP 서버 인스턴스 생성
    httplib::Server svr;

    // CORS 설정
    svr.set_base_dir("./public"); // 정적 파일을 제공하는 경우에만 필요
    svr.set_default_headers({
        {"Access-Control-Allow-Origin", "*"},
        {"Access-Control-Allow-Methods", "GET, POST, OPTIONS"},
        {"Access-Control-Allow-Headers", "Content-Type"}
    });

    // GET 요청에 대한 핸들러 설정
    svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        // 응답으로 "Hello, World!"를 전송
        res.set_content("Hello, World!", "text/plain");
    });

    // 서버를 지정한 포트로 시작
    svr.listen("localhost", 8080);

    return 0;
}
import React, { Component } from "react";
import "./App.css";
import {
  Switch,
  Route,
  HashRouter as Router,
  Redirect
} from "react-router-dom";

import Header from "./components/Header";
import Footer from "./components/Footer";
import HomePage from "./containers/HomePage";

class App extends Component {
  render() {
    return (
      <Router>
        <div className="wrapper">
          <div className="content">
            <Header />
            <div className="content-wrapper">
              <Switch>
                <Route
                  exact
                  path="/"
                  component={() => <Redirect to="/home" />}
                />
                <Route exact path="/home" component={HomePage} />
              </Switch>
            </div>
            <Footer />
          </div>
        </div>
      </Router>
    );
  }
  componentWillMount() {
    document.title = "Open Source IoT Gateway | iotgw.vn";
  }
}

export default App;
